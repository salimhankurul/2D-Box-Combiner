# Why This Exist
This was a hoby project

# Written with C++14
I did the styling , wrote the css

# Live Site: https://darkychat.netlify.app/
Client: Runs on netlify


  ```cpp
   for each (auto box in BoxArray)
		{
			auto currentbox = box;
			for each (auto otherbox in BoxArray)
			{
				if (otherbox == currentbox) // Dont Check Your Shelf
					continue;

				auto Child = BoxFunctions::FindChild(currentbox, BoxArray); // Finds All The Child Box's & add them to father box	
			}
		}
		
	

		//************Delete Child Boxs
		for (int i = 0; i < BoxArray.size(); i++) {
			if (BoxArray.at(i)->IsAlreadyConnected) // means this box is detected to be a child box
			{
				delete BoxArray.at(i); // fixed Memory Leak
				BoxArray.erase(BoxArray.begin() + i);
			}

		};


		for each (auto box in BoxArray)
		{
				renderer.drawbox(box); // Draw The Box
		}
   ```

		


# Site 
![](https://i.gyazo.com/c6bcbe35dbc0f78f2faf4b8778e37721.png)

# Supports Mobile !
![](https://i.gyazo.com/3ff28708a19f6c33b609a2e6ab593d93.png)

# End
