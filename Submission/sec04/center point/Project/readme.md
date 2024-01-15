[![Stars Badge](https://img.shields.io/github/stars/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/stargazers)
[![Forks Badge](https://img.shields.io/github/forks/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/network/members)
[![Pull Requests Badge](https://img.shields.io/github/issues-pr/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/pulls)
[![Issues Badge](https://img.shields.io/github/issues/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/issues)
[![Contributors Badge](https://img.shields.io/github/contributors/jjn7702/SECJ2013-DSA?color=2b9348)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/graphs/contributors)
![Visitors](https://api.visitorbadge.io/api/visitors?path=https%3A%2F%2Fgithub.com%2Fjjn7702%2FSECJ2013-DSA%2FSubmission%2FSample&labelColor=%23d9e3f0&countColor=%23697689&style=flat)

_Don't forget to hit the :star: if you like this repo._

# Inventory Management System - Project
## Objective 

In our data structure and algorithm project, the main objectives of developing the Inventory management system are :
- Develop an Inventory Management System using queue
- Manage inventory in a warehouse by features:
<img align="right" alt="Coding" width="400" src="https://media.licdn.com/dms/image/D4D12AQEGH0grNgGe3w/article-cover_image-shrink_600_2000/0/1663428061606?e=2147483647&v=beta&t=vci9t4_Sun-qVHZfCJOGhoLxGNbjnC5KAuRcbtW-MMs">


📦 𝗮𝗱𝗱𝗶𝗻𝗴 𝗶𝗻𝘃𝗲𝗻𝘁𝗼𝗿𝘆

🗃️ 𝗱𝗲𝗹𝗲𝘁𝗲 𝗶𝗻𝘃𝗲𝗻𝘁𝗼𝗿𝘆

🔍 𝗳𝗶𝗻𝗱 𝗮𝗻 𝗶𝗻𝘃𝗲𝗻𝘁𝗼𝗿𝘆 

    - by code
    
    - by category

📋 𝘀𝗼𝗿𝘁 𝘁𝗵𝗲 𝗶𝗻𝘃𝗲𝗻𝘁𝗼𝗿𝘆 𝗹𝗶𝘀𝘁 

📃 𝗱𝗶𝘀𝗽𝗹𝗮𝘆 𝗶𝗻𝘃𝗲𝗻𝘁𝗼𝗿𝘆 𝗹𝗶𝘀𝘁 
   
    - based on category
   
    - display all list

📤𝗨𝗽𝗱𝗮𝘁𝗲 𝗶𝗻𝘃𝗲𝗻𝘁𝗼𝗿𝘆 𝗶𝗻𝗳𝗼

❗𝗖𝗵𝗲𝗰𝗸 𝗹𝗢𝗪 𝘀𝘁𝗼𝗰𝗸 𝗶𝗻𝘃𝗲𝗻𝘁𝗼𝗿𝘆




## Synopsis📝

The inventory management system is essential for one business or organization to track or manage its warehouse. Our inventory management system is designed to organize the inventory. User can organize the inventory by adding the inventory, deleting the inventory, sorting the inventory by it’s ID in ascending order, and finding the inventory by item or by its category. Since we are using a queue data structure implementation concept, user can only add the inventory at the last position in the list, and delete the first element in the inventory. In addition, user can choose to display the inventory list whether by its category or display full inventory list. Then, we also implement extra features such as updating inventory and checking stock item. User can update the inventory information by entering the item code, then choosing the part they would like to update such as name, type, quantity, or price. Then, the low-stock inventory feature helps the user to check and analyze all the low-stock items and display as a list. The item which has a quantity of less than 10 will be counted as low-stock inventory.

## Problem analysis

𝐑𝐞𝐠𝐚𝐫𝐝𝐢𝐧𝐠 𝐰𝐚𝐫𝐞𝐡𝐨𝐮𝐬𝐞 𝐦𝐚𝐧𝐚𝐠𝐞𝐦𝐞𝐧𝐭, 𝐭𝐡𝐞 𝐜𝐮𝐫𝐫𝐞𝐧𝐭 𝐦𝐚𝐧𝐮𝐚𝐥 𝐢𝐧𝐯𝐞𝐧𝐭𝐨𝐫𝐲 𝐬𝐲𝐬𝐭𝐞𝐦 𝐨𝐟𝐭𝐞𝐧 𝐜𝐚𝐮𝐬𝐞𝐬 𝐢𝐬𝐬𝐮𝐞𝐬 𝐫𝐞𝐥𝐚𝐭𝐞𝐝 𝐭𝐨 𝐞𝐟𝐟𝐢𝐜𝐢𝐞𝐧𝐜𝐲 𝐚𝐧𝐝 𝐚𝐜𝐜𝐮𝐫𝐚𝐜𝐲. 𝐓𝐡𝐢𝐬 𝐦𝐨𝐝𝐞 𝐨𝐟 𝐨𝐩𝐞𝐫𝐚𝐭𝐢𝐨𝐧 𝐢𝐬 𝐧𝐨𝐭 𝐚𝐮𝐭𝐨𝐦𝐚𝐭𝐞𝐝 𝐭𝐨 𝐚𝐜𝐡𝐢𝐞𝐯𝐞 𝐦𝐚𝐱𝐢𝐦𝐮𝐦 𝐫𝐞𝐬𝐨𝐮𝐫𝐜𝐞 𝐨𝐩𝐭𝐢𝐦𝐢𝐳𝐚𝐭𝐢𝐨𝐧, 𝐚𝐧𝐝 𝐢𝐭 𝐦𝐚𝐲 𝐨𝐟𝐭𝐞𝐧 𝐜𝐚𝐮𝐬𝐞

❗️𝐞𝐫𝐫𝐨𝐫𝐬

❗️𝐢𝐧𝐞𝐟𝐟𝐢𝐜𝐢𝐞𝐧𝐜𝐢𝐞𝐬


💡To overcome these challenges💡
Our Inventory Management System aims at using a queue data structure for an organized and automated solution. 

This system simplifies the warehousing process through the ability to add and delete inventory items by the FIFO (First In First Out) rule. It also aims to improve the organization by implementing a sorting feature to allow quick searches and offering a user-friendly interface to view and edit inventory data. The real-time updates and a low-stock alert function, it enable timely actions to avoid shortages. Through these goals and characteristics, the Inventory Management System will provide efficiency and accuracy for every warehouse management.



## Flowchart 💹



## Class Diagram 💹




## Flow of Event 💹


## Linked List Implementation 💹


## Findings 📊

- [Source Code](./source_code)
- [Report](./report)

## Contribution 🛠️
