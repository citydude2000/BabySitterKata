# BabySitterKata
This file is a summary of information about the BabySitterKata application.
The project is a Windows console application created with Visual Studio C++ 2017.

To build the project you have several choices.
If VS2017 is installed, get the latest project source code from Git and open the
babysitterkata.sln file in VS2017. Build the debug version of the interim versions
to observe the development and test history.

To build from the command line, mke sure VS2017 is installed.
Run vcvars64.bat from C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build
or similar location based on the version of vs you have installed.
Open the Developer Command Prompt for VS2017 from the Start menu of Windows 
- look under the VS2017 Tools folder.
From the command line, navigate to the project directory. Type MSBuild. 
This will build the .sln located in the project directory.

To run the applicationfrom a command prompt, navigate to the project x64\debug directory 
and type babysitterkata.exe x y z
where x is desired StartTime, y is StopTime, and z is FamilyID. 
The command should look something like this:

babysitterkata.exe 5 1 2

To close the application press Enter after the final output has been displayed.

The project can be used to calculate the total payment earned by a babysitter based on
their client list and fee schedule. It can be run at a Windows command line prompt 
by executing BabySitterKata.exe. The final released version allows the user to enter 
three command line parameters for start time, stop time, and a family ID which identifies
the appropriate payment schedule per family.

The project was developed using Test Driven Development and history of development versions 
is maintained in Github. Versions in Git cover roughly the following design and test path:

1) Version 1 creates a framework for development and test of the application.
	It will fail because only the structure for the application is provided - not the 
	full implementation. NOT checked in.
2) Version 2 provides a real use case for a particular customer family with the expected
	pay result. It will still fail since no implementation is yet given. NOT checked in.
3) Version 3 provides a simple implementation and three test cases that successfully test
	basic operation. The third case identifies design issues about how to deal with partial hour
	payment. This app assumes periods such as 5 to 8 = 3 hours, while 5 to 8:15 would pay 4 full hours
	rather than partial hour pay. This version is green and therefore checked into Git.
4) Version 4 identifies common code and refactors the code to be more efficient while still
	successfully calculating the basic use cases. Git checkin.
5) Version 5 identifies four cases where input data data is not handled correctly by the basic 
	implementation. These cases will need to be handled by validating the user input, preventing
	incorrect execution, and returning information to the user about what is happening.
	Since the tests are commented out, this version is NOT checked in.
6) Version 6 provides full code implementation to successfully handle incorrect data input.
    Checked in.
7) Version 7 is the final release which allows the user to input command line parameters for start, 
	stop, and family ID and provides useful output information for the user.
	Checked in.
8) Version 8 incorporates suggestions from Pillar and separates the tests into a file with a test class.
	Checked in.
9) Version 9 Remove the test function output in release mode.
	Final version checked in.
