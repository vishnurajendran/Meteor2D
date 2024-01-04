
# Meteor 2D ![Meteor 2D](https://imgbkt-rgon.s3.ap-south-1.amazonaws.com/meteor64.png)  

Meteor is a lightweight 2D game engine designed for simplicity and flexibility in C++. Built on top of SDL (Simple DirectMedia Layer), it provides a clean and intuitive API for game development.

![Meteor wip](https://github.com/vishnurajendran/Meteor2D/blob/main/meteor_in_action.png)

## Features

- **Simple API:** Get started quickly with an easy-to-use C++ API.
- **Extensible:** Customize Meteor2D to the needs of your project.
- **Lightweight:** Focus on essential features for nimble game development.

## Getting Started

1. Clone the repository:

    ```bash
    git clone https://github.com/vishnurajendran/Meteor2D.git
    ```

2. Include the Meteor header in your C++ project.

3. Implement your application class by inheriting from `meteor::Application` and defining the necessary methods.

## Disclaimer

- C++20 features are utilized in the development of this project.
- This project is developed using Visual Studio 2019.
- The Meteor 2D Game Engine has been primarily developed and tested on the Windows operating system.

Please note that while efforts are made to maintain cross-platform compatibility, the current focus and testing have been on the Windows platform.

## TODO
### Core 
- [x] Application and Engine Loop.
- [x] Basic Logging.
- [x] Entities.
- [x] Spatial Entity.
- [x] Renderer and RenderCommands.
- [x] Sprites.
- [x] SpriteSheet Animation.
- [ ] Input System.
    - [x] Keyboard Inputs.
    - [ ] Mouse Inputs. 
- [ ] Gizmos.
- [ ] 2D Physics.
- [ ] Audio.
- [ ] UI System.

### QoL 
- [ ] Create a sample game using Meteor.
- [ ] Improve documentation on advanced features.

### Planned 
- [ ] Meteorite Editor.

## License

Meteor is released under the [MIT License](LICENSE).
