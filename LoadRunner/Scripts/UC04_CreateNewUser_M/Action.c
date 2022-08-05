Action()
{
	int random;
	
	lr_start_transaction("UC04_CreateNewUser");
	
	
	/* HOMEPAGE */

	homepage();
	

	/* SIGN UP */

	lr_start_transaction("sign_up");

	web_reg_find("Text=First time registering? Please complete the form below.", LAST);

	lr_think_time(5);

	web_url("sign up now", 
		"URL=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/home.html", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("sign_up",LR_AUTO);
	
	
	/* USER DETAILS FORM */

	lr_start_transaction("user_details_form");
	
	//web_reg_find("Text=Thank you", LAST);
	
	lr_think_time(5);

	lr_save_string(lr_eval_string("{firsLetter}{secondLetter}{firsLetter}{secondLetter}"), "name");
	lr_save_string(lr_eval_string("{firsLetter}{secondLetter}{firsLetter}{secondLetter}"), "surename_and_password");
	
	web_submit_data("login.pl", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=info", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value={name}", ENDITEM, 
		"Name=password", "Value={surename_and_password}", ENDITEM, 
		"Name=passwordConfirm", "Value={surename_and_password}", ENDITEM, 
		"Name=firstName", "Value={name}", ENDITEM, 
		"Name=lastName", "Value={surename_and_password}", ENDITEM, 
		"Name=address1", "Value={Adress}", ENDITEM, 
		"Name=address2", "Value={City}", ENDITEM, 
		"Name=register.x", "Value=63", ENDITEM, 
		"Name=register.y", "Value=12", ENDITEM, 
		LAST);

	lr_end_transaction("user_details_form",LR_AUTO);
	

	/* CONTINUE REGISTRATION */

	lr_start_transaction("continue_reg");

	web_reg_find("Text=Web Tours reservation pages", LAST);

	lr_think_time(5);

	web_url("button_next.gif", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=menus", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/login.pl", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("continue_reg",LR_AUTO);
	
	
	/* REGISTRATION CONGRATULATIONS */

	lr_start_transaction("registration_congratulations");

	web_reg_find("Text=Welcome", LAST);

	lr_think_time(5);

	web_url("button_next.gif", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=menus", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/login.pl", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("registration_congratulations",LR_AUTO);
	
	
	/* ITINERARY */

	lr_start_transaction("go_itinerary");
	
	web_reg_find("Text=No flights have been reserved", LAST);
	
	lr_think_time(5);
	
	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);
	lr_end_transaction("go_itinerary",LR_AUTO);
	
	
	/* LOGOUT */
	
	random = rand() % 2 + 1;
	
	lr_message("random=%i", random);

	if(random == 2) {
		logout();
	}
	
	lr_end_transaction("UC04_CreateNewUser", LR_AUTO);

	return 0;
}