/*
* Challenge Original Files URL: https://heavyiron.games/downloads/Challenge.zip
*/

//
// HEAVY IRON INTERN PROGRAMMING CHALLENGE
// 
// Thanks for your interest in interning as a programmer at Heavy Iron.
//
// Welcome to the challenge. We expect it will take under two hours to complete.
// Please attempt all questions below.
//
// - Read all the instructions and questions carefully.
// - You may use a compiler, or just use a text editor. Your choice.
// - All work should be done in this one file.
//
// - DO NOT use the internet or other reference material, unless specified.
// - DO NOT use STL or similar templated data structures.
// - DO NOT modify the function definitions.
//
// - DO NOT CHEAT. We're not trying to see if you can cheat.
// 
//
// When finished:
//
// 1) Fill in these details in this cpp file:
//
//		Name										: Jeremy Trifilo
//		Address										: 
//		Email										: 
//		Phone										:
//		Current College								:
//		Current Course								:
//		Expected graduation date					:
//		Previous bachelors (if appropriate)			:
//		Date you could start						:
//		Date you would end (if appropriate)			:
//		Are you available full time all summer		:
//		Are you interested in interning term time*	:
//			* Some of our local interns work full time during the summer, and part time 2..5 
//			  days during term time. This isn't required, but it's interesting to know.
//
// 2) Save your changes, and email just this file to HI-interns@heavy-iron.com
//	  If you have an up to date resume, include that too.
//
// As we receive applications, we’ll pick several for in-house interview, and will then 
// select who will be offered positions.
//
// Good luck, and have fun! :)
//
// Heavy Iron Studios, Inc.
// (c) Copyright 2013

#include <iostream>

struct Vector3
{

	float x, y, z;
};

static const float RADIAN_PI = 3.14159265f / 180.0f;

static const uint64_t POW10_N[20] =
{
	1, 1, 10, 100, 1000, 10000, 100000,
	1000000, 10000000, 100000000, 1000000000
};

/*
 * @usage - Returns my name and date :)
 */
const char* YourNameAndTheDate()
{
	return "Jeremy Trifilo   11/18/2019";
}

/*
 * @numbers - Each value in the array can be any number in the range of a byte value.
 * @count   - This value has no limitation, but let's take into account memory constraints.
 * @regards -
			- With small numbers like 1 through 6 I choose a range of 0 - 255.
			- This will also sort the numbers ascending order from odd first then even.
			- This supports an infinite count and is incredibly fast with low memory consumption.
   @speed - low count 10 was 2-5 micro seconds , and high count 200,000 was 400-700 micro seconds.
 */
void SortOddEven(int* numbers, const int count)
{
	int index = -1;

	int8_t byte_buffer[256] = { 0 };

	for (int i = 0; i < count; ++i)
	{
		byte_buffer[numbers[i] & 0xFF]++;
	}

	for (int i = 1; i <= 255; i += 2)
	{
		for (int n = 0; n < byte_buffer[i]; ++n)
			numbers[++index] = i;
	}

	for (int i = 0; i <= 254; i += 2)
	{
		for (int n = 0; n < byte_buffer[i]; ++n)
			numbers[++index] = i;
	}
}

/*
 * @value - Any number with no limitations we assume it will be  higher then previous number. (Negative values supported).
 * @output - The buffer to write our results to for displaying.
 * @usage - If value is divisable by 3 it'll write Fizz, by 5 it'll write Buzz, Otherwise it'll write the number.
 * @regards - Not going to test speed i know these are the general fast methods and simple ways to calculate this problem.
 */
void FizzBuzz(const int value, char* output)
{
	//Possible Usage In Future Better Than Boolean.
	int8_t word = 0;


	//Adds Fizz or Buzz if applicable.
	if (value % 3 == 0)
	{
		*output++ = 'F';
		*output++ = 'i';
		*output++ = 'z';
		*output++ = 'z';
		word = true;
	}
	if (value % 5 == 0)
	{
		*output++ = 'B';
		*output++ = 'u';
		*output++ = 'z';
		*output++ = 'z';
		word = true;
	}

	//Adds the number if applicable.
	if (!word)
	{
		uint64_t number = value;
		int neg = value < 0;
		if (neg)
			number = -value;
		int len = 0;
		if (number >= 1000000) {
			if (number >= 100000000) {
				if (number >= 1000000000) {
					len = 10;
				}
				else {
					len = 9;
				}
			}
			else {
				if (number >= 10000000) {
					len = 8;
				}
				else {
					len = 7;
				}
			}
		}
		else {
			if (number >= 1000) {
				if (number >= 10000) {
					if (number >= 100000) {
						len = 6;
					}
					else {
						len = 5;
					}
				}
				else {
					len = 4;
				}
			}
			else {
				if (number >= 10) {
					if (number >= 100) {
						len = 3;
					}
					else {
						len = 2;
					}
				}
				else {
					len = 1;
				}
			}
		}

		if (neg)
			*output++ = '-';

		uint64_t reduction = POW10_N[len];

		for (; --len >= 0; )
		{
			int c_value = (int)(number / reduction);
			number -= reduction * c_value;
			*output++ = 48 + c_value;
			reduction = POW10_N[len];
		}
	}

	*output = NULL;
}

/*
* @x1,t1 = Center Position Of Circle 1.
* @x2,y2 = Center Position of Circle 2.
* @r1 = Radius of Circle 1.
* @r2 = Radius of Circle 2.
* @usage - Checks the radius could intersect, but we won't know where, ah well...
*/
bool CirclesIntersect(float x1, float y1, float r1, float x2, float y2, float r2)
{
	float dx = x2 - x1;
	float dy = y2 - y1;
	return (int)(dx * dx + dy * dy) <= (int)(r1 + r2) * (r1 + r2);
}

/*
* @monster_position - the X,Z,Y location of the Monster.
* @apple_position - the X,Z,Y location of the Apple.
* @face_direction - The Vector at which the monsters camera is facing.
* @objectives - If the monster is looking within a 90 angle (45 on left and 45 on right) of the line created.
				between it and the apple it will be successfully looking at the apple.
*/

/*
	Vector3 monsterPos(100, 100, 0);
	Vector3 monsterDir(1, 1, 0);
	Vector3 applePos(150, 125, 0);
*/
bool IsAppleInFrontOfMonster(Vector3& monster_position, Vector3& face_direction, Vector3& apple_position)
{
	float xdiff = apple_position.y - monster_position.x; //50
	float ydiff = apple_position.y - monster_position.y; //25

	int location_angle = (int)(atan2(ydiff, xdiff) * RADIAN_PI);
	int face_angle = (int)(atan2(face_direction.y, face_direction.x) * RADIAN_PI);

	if (location_angle < 0)
		location_angle += 405;
	else
		location_angle += 45;

	if (face_angle < 0)
		face_angle += 405;
	else
		face_angle += 45;

	int difference = face_angle - location_angle;
	if (location_angle > face_angle)
	{
		return difference > -90;
	}
	else
	{
		return difference < 90;
	}
}

/*
* @in - Sends in any 32 bit integer value.
* @usage - Flips the Endianness Order E.g. 0, 8, 16, 24 becomes 24, 16, 8, 0...
* @efficiency - Very simple to read, understand, and incredibly fast.
*/
unsigned int SwapBytes(unsigned int in)
{
	return (int8_t)(in >> 24) |
		(int8_t)(in >> 16) << 8 |
		(int8_t)(in >> 8) << 16 |
		(int8_t)(in >> 0) << 24;
}

/*
* @input = unchangle char array of a sentence.
* @usage = Remove the spaces from this sentence and return the fixed version.
*/
char* StripSpaces(const char* input)
{
	int length = -1;
	int new_length = 0;

	while (input[++length] != NULL)
	{
		if (input[length] == ' ')
			++new_length;
	}

	new_length = length - new_length;

	char* output = (char*)malloc((new_length + 1) * sizeof(char));

	new_length = -1;

	for (int i = 0; i < length; ++i)
	{
		if (input[i] != ' ')
			output[++new_length] = input[i];
	}

	output[++new_length] = 0;

	return output;
}

/*
* @num - the value of which we want to check each digit for how many bars it has.
* @usage = Divide + Conquer to get each digit , we use "0x2F76CB56" which is the compressed bit value of all the bars.
			Then we can obtain each bar amount from it.
*/
int BarsInDisplayedNumber(unsigned int num)
{
	int len = 0;
	if (num >= 1000000) {
		if (num >= 100000000) {
			if (num >= 1000000000) {
				len = 10;
			}
			else {
				len = 9;
			}
		}
		else {
			if (num >= 10000000) {
				len = 8;
			}
			else {
				len = 7;
			}
		}
	}
	else {
		if (num >= 1000) {
			if (num >= 10000) {
				if (num >= 100000) {
					len = 6;
				}
				else {
					len = 5;
				}
			}
			else {
				len = 4;
			}
		}
		else {
			if (num >= 10) {
				if (num >= 100) {
					len = 3;
				}
				else {
					len = 2;
				}
			}
			else {
				len = 1;
			}
		}
	}

	uint64_t reduction = POW10_N[len];

	int bar_count = 0;

	for (; --len >= 0; )
	{
		uint64_t c_value = (int)(num / reduction);
		num -= (int)(reduction * c_value);

		int value = ((0x2F76CB56L >> (c_value * 3)) & 0x7);
		bar_count += value;
		reduction = POW10_N[len];
	}

	return bar_count;
}

/*
* Main Method
*/
int main()
{
	//Challenge 0
	std::cout << "0) Name And Date: " << YourNameAndTheDate();

	//Challenge 1
	const int length = 6;
	int numbers[length] = { 1, 2, 3, 4, 5, 6 };
	SortOddEven(numbers, length);


	//Challenge 2.
	char temp[16];
	FizzBuzz(15, temp);


	//Challenge 3.
	bool intersects = CirclesIntersect(0, 0, 5, 10, 0, 4);


	//Challenge 4.
	Vector3 monsterPos = { 100, 100, 0 }, 
			monsterDir = {  -1,  -1, 0 }, 
			applePos   = { 150, 125, 0 };

	bool result = IsAppleInFrontOfMonster(monsterPos, monsterDir, applePos);


	//Challenge 5.
	unsigned int input = 0x12345678;
	unsigned int shuffled = SwapBytes(input);


	//Challenge 6.
	const char* with_spaces = "Oh My Word!";
	const char* stripped = StripSpaces(with_spaces);


	//Challenge 7.
	int bars = BarsInDisplayedNumber(1234567890); 


	//Print Out's Of Answers.
	std::cout << "\n1) SORT ODD EVEN: ";
	for (int i = 0; i < length - 1; ++i)
		std::cout << numbers[i] << ',';
	std::cout << numbers[length - 1];

	std::cout << "\n2) FIZZBUZZ: " << temp;
	std::cout << "\n3) CIRCLE INTERSECTION: " << (intersects ? "YES." : "NO.");
	std::cout << "\n4) APPLE IS " << (result ? "IN FRONT OF" : "BEHIND") << " THE MONSTER.";
	printf("\n5) SWAP BYTES 0x%x => 0x%x", input, shuffled);
	std::cout << "\n6) STRIP SPACES: " << with_spaces << " => " << stripped;
	std::cout << "\n7) BARS IN DISPLAY: " << bars << '\n';


	//Free The Memory :)
	free((void*)stripped);

	return 0;
}