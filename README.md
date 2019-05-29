# BabySitterKata
repos for BabySitterKata development

1) Version 1 creates a framework for development and test of the application.
	It will fail because only the structure for the application is provided - not the 
	full implementation. NOT checked in.
2) Version 2 provides a real use case for a particular customer family with the expected
	pay result. It will still fail since no implementation is yet given. NOT checked in.
3) Version 3 provides a simple implementation and three test cases that successfully test
	basic operation. The third case identifies design issues about how to deal with partial hour
	payment. This app assumes periods such as 5 to 8 = 3 hours, while 5 to 8:15 would pay 4 full hours
	rather than partial hour pay. This version is green and therefore checked into Git.
  
