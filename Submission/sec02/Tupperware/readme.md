[![Stars Badge](https://img.shields.io/github/stars/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/stargazers)
[![Forks Badge](https://img.shields.io/github/forks/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/network/members)
[![Pull Requests Badge](https://img.shields.io/github/issues-pr/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/pulls)
[![Issues Badge](https://img.shields.io/github/issues/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/issues)
[![Contributors Badge](https://img.shields.io/github/contributors/jjn7702/SECJ2013-DSA?color=2b9348)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/graphs/contributors)
![Visitors](https://api.visitorbadge.io/api/visitors?path=https%3A%2F%2Fgithub.com%2Fjjn7702%2FSECJ2013-DSA%2FSubmission%2FSample&labelColor=%23d9e3f0&countColor=%23697689&style=flat)

_Don't forget to hit the :star: if you like this repo._

<h1>Restaurant Management System</h1>
<h1>Assignment 1</h1>
<h2>Description 📝</h2>
<p>The Restaurant Management system is designed to manage orders from customers. This system is for the admin of the restaurant to manage orders from the customers and for the customer to make orders from the list of menu provided. </p>

<h2> Prepared by 🧑‍💻</h2>

| Name             | Matric Number | Photo                                                         |
| :---------------- | :-------------: | :------------------------------------------------------------: |
| WAN NUR SOFEA BINTI MOHD HASBULLAH   | A22EC0115        | <a href="https://www.freepik.com/icon/graduated_4537051" title="Icon by Trazobanana"><img src="https://github.com/wannursofea/Mypicture/blob/main/UTM_GAMBAR_ID_CARD-removebg-preview.png?raw=true" width=100px, height=100px>     |
| NADHRAH NURSABRINA BINTI ZULAINI     | A22EC0224        | <a href="https://www.freepik.com/icon/graduated_4537051" title="Icon by Trazobanana"><img src="https://github.com/drshahizan/software-engineering/blob/main/proposal/submission/sec02/Alpha/Photo/kad%20matrik.jpg?raw=true" width=100px, height=100px>         |
| NUR ALEYSHA QURRATU'AINI BINTI MAT SALLEH       | A22EC0241        | <a href="https://www.freepik.com/icon/graduated_4537051" title="Icon by Trazobanana"><img src="https://github.com/drshahizan/software-engineering/blob/main/proposal/submission/sec02/Alpha/Photo/GAMBAR%20KAD%20MATRIK%20UTM.jpeg?raw=true" width=100px, height=100px>         |

<h2>Flow of system</h2>

<p>
1. Customer press enter to see the menu <br>
2. All menu displays (default) <br>
3. System ask if want to choose order OR view in new way(sorting implemented) OR by search <br>
4. Customer choose sorting view <br>
5. System ask how the sorting based on (food id, price) <br>
6. Customer choose one of the option <br>
7. System displays again the menu <br>
8. Go to number 14 <br>
9. Customer search certain menu <br>
10. System display the food <br>
11. System ask if customer want to add the menu to the cart <br>
12. Customer enter Y/y <br>
13. The chosen menu is saved in the system <br>
14. System ask if want to continue order <br>
15. If yes, customer can make multiple orders until customer enter N/n to stop <br> 
15. Customer finished ordering <br>
16. System displays list of orders and calculate total price <br>
17. System displays the chosen menu, quantity, and price 
</p>

<h3>Report Assignment 1</h3>
<a href="https://docs.google.com/document/d/1Zo1a1CUOtAN9jOG7cpsusQ4GQOKJwSBSsdrvTltsyAc/edit?usp=sharing"><img src="./images/document1.png" width="35px" height="35px" ></a> 


<h1>Assignment 2</h1>
<p>
1. Start <br>
2. Define a class “Menu” <br>
3. Define a class “Node” <br>
4. Define a class “OrderList” <br>
5. Open the file “menu.txt” for reading <br>
	5.1. If the file cannot be opened, display an error message <br>
6. While not at the end of the file <br>
	6.1 Read menu data from file and populate OrderList <br>
7. End While <br>
8. Do <br>
	8.1 Print menu options <br>
	8.2 Read user option <br>
	8.3 Switch user option <br>
		8.3.1 Case 1 : Add menu <br>
			8.3.1.1 Prompt user to enter food ID, food name, category and price <br>
			8.3.1.2 Read all food ID, food name, category and price <br>
			8.3.1.3 Print ins either to add menu at front, middle or end of linked list <br>
			8.3.1.4 Read user ins <br>
			8.3.1.5 Switch user ins <br>
				8.3.1.5.1 Case 1 : call insertFront function <br>
				8.3.1.5.2 Case 2 : call insertMiddle function <br>
				8.3.1.5.3 Case 3 : call insertEnd function <br>
			8.3.1.6 End switch <br>
		8.3.2 Case 2 : Delete menu <br>
			8.3.2.1 Print ins either to delete menu at front, middle or end of linked list <br>
			8.3.2.2 Read user ins <br>
			8.3.2.3 Switch user ins <br>
				8.3.2.3.1 Case 1 : call deleteFront function <br>
				8.3.2.3.2 Case 2 : call deleteEnd function <br>
				8.3.2.3.3 Case 3 : call deleteMiddle function <br>
			8.3.2.4 End switch <br>
		8.3.3 Case 3 : Find Node <br>
			8.3.3.1 Print search choice either name, category or food ID <br>
			8.3.3.2 Read search choice <br>
			8.3.3.3 If (choice == N || choice == n) <br>
				8.3.3.3.1 Read food name entered by user <br>
				8.3.3.3.2 Display menu according to the food name <br>
			8.3.3.4 Else if (choice == C || choice == c) <br>
				8.3.3.4.1 Read category entered by user <br>
				8.3.3.4.2 Display all menu list according to category <br>
			8.3.3.5 Else if (choice == F || choice == f) <br>
				8.3.3.5.1 Read food ID entered by user <br>
				8.3.3.5.2 Display menu according to food ID <br>
			8.3.3.6 End if <br>
		8.3.4 Case 4 : Sort menu <br>
			8.3.4.1 Print sortBy to choose either to sort by food ID or Price <br>
			8.3.4.2 Read user sortBy <br>
			8.3.4.3 Switch user sortBy <br>
				8.3.4.3.1 Case 1 : Print sortIn to choose either to sort in ascending or descending <br>
				8.3.4.3.2 Read user sortIn <br>
				8.3.4.3.3 Switch user sortIn <br>
					8.3.4.3.3.1 Case 1 : Ascending order. Call sortFoodId(true) function <br>
					8.3.4.3.3.2 Case 2 : Descending order : Call sortFoodId(false) function <br>
				8.3.4.3.4 End switch <br>
				8.3.4.3.5 Case 2 : Print sortIn to choose either sort in ascending or descending order <br>
				8.3.4.3.6 Read user sortIn <br>
				8.3.4.3.7 Switch user sortIn <br>
						8.3.4.3.7.1 Case 1 : Ascending order. Call sortFoodPrice(true) function <br>
						8.3.4.3.7.1 Case 2 : Descending order. Call sortFoodPrice(false) function <br>
				8.3.4.3.8 End switch <br>
		8.3.5 Case 5 : Display menu <br>
			8.3.5.1 Call displayNodes function <br>
		8.3.6 Default: Print "Invalid option. Please try again." <br>
	8.4 End switch <br>
	8.5 Print "Do you want to continue? (Y/N): " <br>
	8.5 Read user choice <br>
9. End while user choice == Y or choice == y <br>
10. Print "Thank youm see you again!" <br>

<h3>Report Assignment 2</h3>
<a href="https://docs.google.com/document/d/1svn2Y7EqNPjK_v5B6-LRwq7I5qcATWdD85veZjv7Efs/edit?usp=sharing"><img src="./images/document1.png" width="35px" height="35px" ></a> 

</p>
<h2>Findings 📊</h2>
- <a href="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/Tupperware/Assignment1/assingment1.md">Assignment 1 </a><br>
- Assignment 2<br>
- Project<br>

## Contribution 🛠️
Please create an [Issue](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/issues) for any improvements, suggestions or errors in the content.

[![Visitors](https://api.visitorbadge.io/api/visitors?path=https%3A%2F%2Fgithub.com%2Fjjn7702&labelColor=%23697689&countColor=%23555555&style=plastic)](https://visitorbadge.io/status?path=https%3A%2F%2Fgithub.com%2Fjjn7702)
![](https://hit.yhype.me/github/profile?user_id=81284918)

