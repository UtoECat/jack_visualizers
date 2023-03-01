/* OSC Session Manager Extension for jackutils library.
 * Copyright (C) UtoECat 2022. All rights Reserved!

 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

/*
 * Returns is GUI enabled for us.
 * If this functions returns true, then you SHOULD show your window.
 * Else you SHOULD hide it, and draw nothing.
 *
 * If there is no session manager, returns true until ju_set_gui 
 * is not called.
 *
 * @arg context
 * @ret 1 if enabled.
 */
JU_API int (ju_need_gui) (ju_ctx_t*);

/*
 * Set ju_need_gui returned value and send it to session manager.
 *
 * If there is no session manager, setting this to 0 makes 
 * ju_is_online return 0 too!
 * 
 * @arg context
 * @arg show gui
 */
JU_API void (ju_set_gui) (ju_ctx_t*, int);

/*
 * Returns information about session manager, if available.
 *
 * @arg context
 * @ret session manager info string or NULL if session manager is not available
 *
 */
JU_API ju_cstr_t (ju_osc_info) (ju_ctx_t* ctx);

/*
 * Returns OSC path to store your session data.
 * If there is no session manager, returns "~/.local/share/jackutils/"
 *
 * From NSM Documentation :
 * returns a path name in the form client_name.ID, assigned to the client
 * for storing its project data. The client MUST choose one of the four 
 * strategies below to save, so that every file in the session can be 
 * traced back to a client and, vice versa, a client name.ID can be used to 
 * look up all its files. (For example to clean up the session dir) :
 *
 * 1. The client has no state and does not save at all
 * 1.1 and it MUST NOT misuse e.g. ~/.config to save session specific
 * 		 information e.g. synth-instrument settings
 * 2. The client may use the path client_name.ID directly, resulting in
 * a file client_name.ID in the session directory
 * 3. The client may append its native file extension (e.g. .json) 
 * to the path client_name.ID
 * 4. The client may use the path as directory, creating arbitrary 
 * files below, for example recorded .wav.
 * 4.1 and it MUST NOT use the client ID below this point. This way
 * 		 the data stays transferable by hand to another client 
 * 		 instance (in another session).
 *
 * @arg context
 * @ret path to load and save session data
 */
JU_API ju_cstr_t (ju_osc_path) (ju_ctx_t* ctx);

JU_API void (ju_pool_events) (ju_ctx_t*);
