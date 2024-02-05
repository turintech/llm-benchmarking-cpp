#include "winheader.h"

/** @brief display a message
 *
 * @param message The message to display
 */
void
OsWinHeader::ShowMessage(const char *message) {
  MessageBox(NULL, message, "Message", MB_OK | MB_ICONINFORMATION);
}
