//
//         APPLICATION STATE DIAGRAM
//          
//                     ( )
//                      |
//                 (ANY EVENT)
//                      |
//                      V
//             +-----------------+
//             | CHECKING  STATE |<------
//             +-----------------+       |
//                      |                |
//                  WORK EVENT         CHECK
//                      |              EVENT
//                      V                |
//             +-----------------+       |
//      ------>|  WORKING STATE  |-------
//     |       +-----------------+
//     |                |
//  WAUKEUP        SLEEP EVENT
//   EVENT              |
//     |                V
//     |       +-----------------+
//      -------| SLEEPING  STATE |
//             +-----------------+
//                      |
//                RESTART EVENT
//                      |
//                      V
//                     (O)
//
//  Powered by feallee@hotmail.com on 2024/7/18.
//