package com.spring.ase;

import java.util.ArrayList;

import javax.naming.NamingException;
import javax.servlet.http.HttpServletRequest;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.servlet.ModelAndView;

import com.spring.ase.command.ICommand;
import com.spring.ase.command.ListCmd;
import com.spring.ase.dao.LoginDao;
import com.spring.ase.dao.MyAccountDao;
import com.spring.ase.dto.BDto;
import com.spring.ase.dto.MyAccountDto;

@Controller
public class MyController {

	@RequestMapping("/list")
	public String list(Model model) throws NamingException {

		LoginDao dao = new LoginDao();
		ArrayList<BDto> dtos = dao.list();
		model.addAttribute("list", dtos);
		return "list";
	}

	@RequestMapping("/view")
	public String view(Model model) {

		model.addAttribute("id", "hello spring framework");

		return "view";
	}

	@RequestMapping("/login")
	public String login(Model model) {

		return "login";
	}

	

	@RequestMapping("/useraccount")
	public String useraccount(Model model) {

		return "useraccount";
	}

	@RequestMapping(method = RequestMethod.POST, value = "/user")
	public ModelAndView loginConfirm(HttpServletRequest httpServletRequest, Model model) {
		boolean validate = false;
		String id = httpServletRequest.getParameter("id");
		String pw = httpServletRequest.getParameter("pw");
		httpServletRequest.getSession().setAttribute("id", id);
		LoginDao dao;
		try {
			dao = new LoginDao();
			validate = dao.checkLoginDetails(id,pw);
		} catch (NamingException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			validate = false;
		}	
		ModelAndView mv = new ModelAndView();
		mv.addObject("userId", id);
		mv.addObject("userPw", pw);
		if(validate) {
		mv.setViewName("loginDisplay");
		}else {
		mv.addObject("error", "Invalid login details. Please try again!!!");
		mv.setViewName("login");	
		}
		
		return mv;

		// return "loginDisplay";
	}

	
	@RequestMapping("/member/memberView")
	public String member(HttpServletRequest httpservletrequest, Model model) {

		String id = httpservletrequest.getParameter("id");
		String pw = httpservletrequest.getParameter("pw");

		model.addAttribute("id", id);
		model.addAttribute("pw", pw);

		return "/member/memberView";
	}

	@RequestMapping("/account")
	public ModelAndView createAccount(HttpServletRequest httpservletrequest, Model model) {

		boolean validate = false;

		String id = httpservletrequest.getParameter("id");
		String pw = httpservletrequest.getParameter("pw");

		String name = httpservletrequest.getParameter("name");
		String phone = httpservletrequest.getParameter("phone");
		BDto bdto = new BDto(id, pw, name, phone);

		LoginDao dao;
		try {
			dao = new LoginDao();
			dao.createMember(bdto);
			validate = true;
		} catch (NamingException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			validate = false;
		}
		ModelAndView mv = new ModelAndView();

		if (validate) {
			mv.setViewName("/member/accountSuccess");
		} else {
			mv.addObject("error", "Provide valid details. Please try again!!!");
			mv.setViewName("useraccount");
		}

		model.addAttribute("name", name);

		return mv;
	}

}
