#include "Update.h"

void Create_Field_Buffer(struct Field *field) {
	for (int x = 0; x < field->w; x++) {
		for (int y = 0; y < field->h; y++) {
			field->bell[x][y].active = field->cell[x][y].active;
		}
	}
}

bool Get_Cell_State(struct Cell cell) {
	if (cell.neighbours < 2) { return false; }	// Dies of lonelieness
	if (cell.neighbours > 3) { return false; }	// Dies of overcrowding
	if (cell.neighbours == 3) { return true; }	// Becomes alive
	return cell.active;							// Stays as is
}

void Get_Neighbours(struct Field *field, struct Game *game) {
	/*	We are cell 5
		1	2	3
		4	5	6
		7	8	9	
	*/

	// Copy current state to the buffer
	Create_Field_Buffer(field);

	for (int x = 0; x < field->w; x++) {
		for (int y = 0; y < field->h; y++) {
			// Reset neighbours to zero each frame
			field->cell[x][y].neighbours = 0;

			// Top Left Corner
			if ((x == 0) && (y == 0)) {
				// Cell 1
				field->cell[x][y].neighbours += field->bell[field->w-1][field->h-1].active;
				// Cell 2
				field->cell[x][y].neighbours += field->bell[x][field->h-1].active;
				// Cell 3
				field->cell[x][y].neighbours += field->bell[x+1][field->h-1].active;
				// Cell 4
				field->cell[x][y].neighbours += field->bell[field->w-1][y].active;
				// Cell 6
				field->cell[x][y].neighbours += field->bell[x+1][y].active;
				// Cell 7
				field->cell[x][y].neighbours += field->bell[field->w-1][y+1].active;
				// Cell 8
				field->cell[x][y].neighbours += field->bell[x][y+1].active;
				// Cell 9
				field->cell[x][y].neighbours += field->bell[x+1][y+1].active;
			} // Bottom Left Corner
			else if ((x == 0) && (y == field->h-1)) {
				// Cell 1
				field->cell[x][y].neighbours += field->bell[field->w-1][y-1].active;
				// Cell 2
				field->cell[x][y].neighbours += field->bell[x][y-1].active;
				// Cell 3
				field->cell[x][y].neighbours += field->bell[x+1][y-1].active;
				// Cell 4
				field->cell[x][y].neighbours += field->bell[field->w-1][y].active;
				// Cell 6
				field->cell[x][y].neighbours += field->bell[x+1][y].active;
				// Cell 7
				field->cell[x][y].neighbours += field->bell[field->w-1][0].active;
				// Cell 8
				field->cell[x][y].neighbours += field->bell[x][0].active;
				// Cell 9
				field->cell[x][y].neighbours += field->bell[x+1][0].active;
			} // Top Right Corner
			else if ((x == field->w-1) && (y == 0)) {
				// Cell 1
				field->cell[x][y].neighbours += field->bell[x-1][field->h-1].active;
				// Cell 2
				field->cell[x][y].neighbours += field->bell[x][field->h-1].active;
				// Cell 3
				field->cell[x][y].neighbours += field->bell[0][field->h-1].active;
				// Cell 4
				field->cell[x][y].neighbours += field->bell[x-1][y].active;
				// Cell 6
				field->cell[x][y].neighbours += field->bell[0][y].active;
				// Cell 7
				field->cell[x][y].neighbours += field->bell[x-1][y+1].active;
				// Cell 8
				field->cell[x][y].neighbours += field->bell[x][y+1].active;
				// Cell 9
				field->cell[x][y].neighbours += field->bell[0][y+1].active;
			} // Bottom Right Corner
			else if ((x == field->w-1) && (y == field->h-1)) {
				// Cell 1
				field->cell[x][y].neighbours += field->bell[x-1][y-1].active;
				// Cell 2
				field->cell[x][y].neighbours += field->bell[x][y-1].active;
				// Cell 3
				field->cell[x][y].neighbours += field->bell[0][y-1].active;
				// Cell 4
				field->cell[x][y].neighbours += field->bell[x-1][y].active;
				// Cell 6
				field->cell[x][y].neighbours += field->bell[0][y].active;
				// Cell 7
				field->cell[x][y].neighbours += field->bell[x-1][0].active;
				// Cell 8
				field->cell[x][y].neighbours += field->bell[x][0].active;
				// Cell 9
				field->cell[x][y].neighbours += field->bell[0][0].active;
			} // Left Column
			else if (x == 0) {
				// Cell 1
				field->cell[x][y].neighbours += field->bell[field->w-1][y-1].active;
				// Cell 2
				field->cell[x][y].neighbours += field->bell[x][y-1].active;
				// Cell 3
				field->cell[x][y].neighbours += field->bell[x+1][y-1].active;
				// Cell 4
				field->cell[x][y].neighbours += field->bell[field->w-1][y].active;
				// Cell 6
				field->cell[x][y].neighbours += field->bell[x+1][y].active;
				// Cell 7
				field->cell[x][y].neighbours += field->bell[field->w-1][y+1].active;
				// Cell 8
				field->cell[x][y].neighbours += field->bell[x][y+1].active;
				// Cell 9
				field->cell[x][y].neighbours += field->bell[x+1][y+1].active;
			} // Right Column
			else if (x == field->w-1) {
				// Cell 1
				field->cell[x][y].neighbours += field->bell[x-1][y-1].active;
				// Cell 2
				field->cell[x][y].neighbours += field->bell[x][y-1].active;
				// Cell 3
				field->cell[x][y].neighbours += field->bell[0][y-1].active;
				// Cell 4
				field->cell[x][y].neighbours += field->bell[x-1][y].active;
				// Cell 6
				field->cell[x][y].neighbours += field->bell[0][y].active;
				// Cell 7
				field->cell[x][y].neighbours += field->bell[x-1][y+1].active;
				// Cell 8
				field->cell[x][y].neighbours += field->bell[x][y+1].active;
				// Cell 9
				field->cell[x][y].neighbours += field->bell[0][y+1].active;
			} // Top Row
			else if (y == 0) {
				// Cell 1
				field->cell[x][y].neighbours += field->bell[x-1][field->h-1].active;
				// Cell 2
				field->cell[x][y].neighbours += field->bell[x][field->h-1].active;
				// Cell 3
				field->cell[x][y].neighbours += field->bell[x+1][field->h-1].active;
				// Cell 4
				field->cell[x][y].neighbours += field->bell[x-1][y].active;
				// Cell 6
				field->cell[x][y].neighbours += field->bell[x+1][y].active;
				// Cell 7
				field->cell[x][y].neighbours += field->bell[x-1][y+1].active;
				// Cell 8
				field->cell[x][y].neighbours += field->bell[x][y+1].active;
				// Cell 9
				field->cell[x][y].neighbours += field->bell[x+1][y+1].active;
			} // Bottom Row
			else if (y == field->h-1) {
				// Cell 1
				field->cell[x][y].neighbours += field->bell[x-1][0].active;
				// Cell 2
				field->cell[x][y].neighbours += field->bell[x][0].active;
				// Cell 3
				field->cell[x][y].neighbours += field->bell[x+1][0].active;
				// Cell 4
				field->cell[x][y].neighbours += field->bell[x-1][y].active;
				// Cell 6
				field->cell[x][y].neighbours += field->bell[x+1][y].active;
				// Cell 7
				field->cell[x][y].neighbours += field->bell[x+1][y-1].active;
				// Cell 8
				field->cell[x][y].neighbours += field->bell[x][y-1].active;
				// Cell 9
				field->cell[x][y].neighbours += field->bell[x-1][y-1].active;
			}
			else if (x > 0 && x < field->w - 1 && y > 0 && y < field->h - 1) {
				// Cell 1
				field->cell[x][y].neighbours += field->bell[x-1][y-1].active;
				// Cell 2
				field->cell[x][y].neighbours += field->bell[x][y-1].active;
				// Cell 3
				field->cell[x][y].neighbours += field->bell[x+1][y-1].active;
				// Cell 4
				field->cell[x][y].neighbours += field->bell[x-1][y].active;
				// Cell 6
				field->cell[x][y].neighbours += field->bell[x+1][y].active;
				// Cell 7
				field->cell[x][y].neighbours += field->bell[x-1][y+1].active;
				// Cell 8
				field->cell[x][y].neighbours += field->bell[x][y+1].active;
				// Cell 9
				field->cell[x][y].neighbours += field->bell[x+1][y+1].active;
			}
			// Check if cell should live or die aka pretend you are God (like any C coder really)
			if (!game->paused)
				field->cell[x][y].active = Get_Cell_State(field->cell[x][y]);			
		}
	}
}

void Update(struct Game *game, struct Field *field) {

	// Enable mouse when game is paused
	if (game->paused) {
		// Iterate through every cell in field
		for (int x = 0; x < field->w; x++) {
			for (int y = 0; y < field->h; y++) {
				// Check if cursor is hovering above cell
				field->cell[x][y].hover =	
						(field->cell[x][y].x <= game->x + 2 &&
						field->cell[x][y].x + field->res >= game->x - 2 &&
						field->cell[x][y].y <= game->y + 2 &&
						field->cell[x][y].y + field->res >= game->y - 2);
	
				// Activate/Deactive cells with left/right mouse
				if (field->cell[x][y].hover && game->l_mouse) {
					field->cell[x][y].active = true;
				} else if (field->cell[x][y].hover && game->r_mouse) {
					field->cell[x][y].active = false;
				}	
			}
		}
	}

	// Do the game of life
	Get_Neighbours(field, game);
}
