# Editor
* Make an editor that has deps on both engine and game
* Serialization data for each game object (spawmer, player etc) in a level file
* The editor modifies this and the game loads this .level file.
* This editor is itself an app from the engine thats draws to a fbo in imgui dock in my app.

* collision: ICollidable
* auto register via dyn cast when adding obj to scene?
* Level loader loads the data and add it to the scene of the game.

# Low level systems
* Handle manager ? [see this blog post](https://floooh.github.io/2018/06/17/handles-vs-pointers.html)
* Serialization binary custom (+streams)
