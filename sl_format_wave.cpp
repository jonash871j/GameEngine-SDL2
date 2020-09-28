#include "sl_format_wave.h"
#include "sl_sound.h"
#include "sl_ec_file_stream.h"

namespace SoundLib
{
	FormatWave::FormatWave()
		: Format(){}

	FormatWave::FormatWave(cwstring path)
	{
		Import(path);
	}

	void FormatWave::ImportHeader()
	{
		SoundQuality quality;

		// Reads file marker "RIFF"
		if (ReadDWORD() != 1179011410)		 
			ThrowInvalidFile();
		// Reads file size
		size = ReadDWORD();
														 
		// Reads file type header should always be "WAVE"
		if (ReadDWORD() != 1163280727)		 
			ThrowInvalidFile();				 
											 
		// Reads format chunk marker
		formatChunk = ReadDWORD();			 
		
		// Reads length of format data
		formatDataLength = ReadDWORD();		 
		
		// Reads type of format
		quality.type = (WaveType)ReadWORD();
		
		// Reads number of Channels
		quality.channels = ReadWORD();
		
		// Reads sample rate 44100hz CD quality
		quality.sampleRate = ReadDWORD();
		
		// Skips (Sample Rate * BitsPerSample * Channels) / 8 & (BitsPerSample * Channels)
		ReadSkip(6);						 
		
		// Reads Bits per sample
		quality.bitsPerSample = ReadWORD();
					
		// Reads file start marker should always be "data"									 
		if (ReadDWORD() != 1635017060)       
			ThrowInvalidFile();			     
		
		// Reads size of the data section.		
		sizeDataSection = ReadDWORD();	  

		// Creates sound
		sound = new Sound(quality);
	}
	void FormatWave::ImportBlocks()
	{
		uint8* buffers = new uint8[size];
		fileStream->inFile.read(buffers, size);
		sound->CreateBuffers(buffers, size);
	}
}
