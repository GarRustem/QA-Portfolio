Action()
{
	int random;
	
	lr_start_transaction("UC05_Itinerary");
	
	
	/* HOMEPAGE */
	
	homepage();
	
	
	/* LOGIN */
	
	login();
	

	/* ITINERARY */

	lr_start_transaction("go_itinerary");
	
	web_reg_find("Text=scheduled flights", LAST);
	
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
	
	
	/* FLIGHTS */

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
	

	/* FIND FLIGHT */

	lr_start_transaction("find_flight");
	
	web_reg_find("Text=Flight Selections", LAST);
	
	lr_think_time(5);

/*Correlation comment - Do not change!  Original value='011;644;07/04/2022' Name ='outboundFlight' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=outboundFlight",
		"TagName=input",
		"Extract=value",
		"Name=outboundFlight",
		"Type=radio",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		LAST);

/*Correlation comment - Do not change!  Original value='101;644;07/05/2022' Name ='returnFlight' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=returnFlight",
		"TagName=input",
		"Extract=value",
		"Name=returnFlight",
		"Type=radio",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		LAST);

	web_submit_data("reservations.pl",
		"Action=http://localhost:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome",
		"Snapshot=t4.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=depart", "Value={city}", ENDITEM,
		"Name=departDate", "Value={departDate}", ENDITEM,
		"Name=arrive", "Value={city}", ENDITEM,
		"Name=returnDate", "Value={returnDate}", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=roundtrip", "Value=on", ENDITEM,
		"Name=seatPref", "Value={seatPref}", ENDITEM,
		"Name=seatType", "Value={seatType}", ENDITEM,
		"Name=.cgifields", "Value=roundtrip", ENDITEM,
		"Name=.cgifields", "Value=seatType", ENDITEM,
		"Name=.cgifields", "Value=seatPref", ENDITEM,
		"Name=findFlights.x", "Value=31", ENDITEM,
		"Name=findFlights.y", "Value=8", ENDITEM,
		LAST);

	lr_end_transaction("find_flight",LR_AUTO);
	

	/* SELECT FLIGHT */

	lr_start_transaction("select_flight");
	
	web_reg_find("Text=Flight Reservation", LAST);
	
	lr_think_time(5);

	web_submit_data("reservations.pl_2",
		"Action=http://localhost:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/reservations.pl",
		"Snapshot=t5.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=outboundFlight", "Value={outboundFlight}", ENDITEM,
		"Name=returnFlight", "Value={returnFlight}", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=seatType", "Value={seatType}", ENDITEM,
		"Name=seatPref", "Value={seatPref}", ENDITEM,
		"Name=reserveFlights.x", "Value=38", ENDITEM,
		"Name=reserveFlights.y", "Value=9", ENDITEM,
		LAST);

	lr_end_transaction("select_flight",LR_AUTO);
	
	
	/* LOGOUT */
	
	random = rand() % 2 + 1;
	
	lr_message("random=%i", random);

	if(random == 2) {
		logout();
	}
	
	lr_end_transaction("UC05_Itinerary",LR_AUTO);

	return 0;
}