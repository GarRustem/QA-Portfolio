Action()
{
	int random;
	
	lr_start_transaction("UC03_UserAuth");
	
	
	/* HOMEPAGE */
	
	homepage();
	
	
	/* LOGIN */
	
	login();
	
	
	/* FLIGHTS */
	
	random = rand() % 2 + 1;
	
	lr_message("random=%i", random);

	if(random == 2) {
		lr_start_transaction("flights");
	
		web_reg_find("Text=Flight Selections", LAST);
	
		lr_think_time(5);

		web_url("Search Flights Button", 
			"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
			"TargetFrame=body", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
			"Snapshot=t3.inf", 
			"Mode=HTML", 
			LAST);

		lr_end_transaction("flights",LR_AUTO);
	}
	

	/* LOGOUT */
	
	random = rand() % 2 + 1;
	
	lr_message("random=%i", random);

	if(random == 2) {
		logout();
	}
	
	lr_end_transaction("UC03_UserAuth", LR_AUTO);

	return 0;
}