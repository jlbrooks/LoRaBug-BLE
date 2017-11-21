# LoRaBug-BLE

Combines TI's Project 0 BLE stack project with the Openchirp [LoraBug LoRaWAN platform](https://github.com/OpenChirp/LoRaBug_Firmware).

# Setup

## Requirements
1. Install [Ti-RTOS `2.20.1.08`](http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/tirtos/index.html)
2. Install the [TI BLE-SDK `2.2.1`](http://www.ti.com/tool/BLE-STACK)
3. Install BLE Simplelink Academy ([link](http://software-dl.ti.com/lprf/simplelink_academy/overview.html), the big red button under `Getting Started`)

## Import projects/build/flash
This part is a bit weird, as the BLE setup utilizes two projects: the 'app' and the 'stack'. I'm not sure if we should freeze a version of the stack in source control or not - here we import from the simplelink academy.

1. Import the basic Project 0.
    1. Open the classic resource explorer (`View -> Resource Explorer Classic`)
    2. Browse to `SimpleLink Academy -> Bluetooth low energy -> Projects -> Project 0`
    3. Select `App CC2650 LaunchPad`, and click the link to import the project into CCS
    4. There should now be two projects in the workspace: `project_zero_stack_cc2650` and `project_zero_app_cc2650launchxl`
2. Delete `project_zero_app_cc2650launchxl` from the workspace, as that is what this project replaces. You may need to go into your workspace folder and delete the project folder manually for the next step to work.
3. Clone this project, and import it into CCS.
3. Build and flash the stack project, but do not run it. The stack does not have an entry point, and gets loaded into the upper portion of memory first.
4. Build and flash this project, and then run it. Using a bluetooth scanner, you should see a device named `Project Zero` with a service that lets you read/write a string value.
