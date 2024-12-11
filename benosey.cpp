/*
benosey.cpp: Grab text data from BeOS/Haiku clipboard
Spit it out in the terminal
Copyright 2024 Matt "Pius Bird" Arnold

Permission to use, copy, modify, and/or distribute this software for any
 purpose with or without fee is hereby granted, provided that the above 
copyright notice and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED “AS IS” AND THE AUTHOR DISCLAIMS ALL WARRAN
TIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF ME
RCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR AN
Y SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHA
TSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTIO
N OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

#include <Application.h>
#include <Clipboard.h>
#include <stdio.h>

int main(void)
{

    const char *text; 
    ssize_t* len;
    BMessage *clip = (BMessage *)NULL;
    BClipboard *sys = new BClipboard("system");
    if (sys->Lock()) {
       if (clip = sys->Data())
          clip->FindData("text/plain", B_MIME_TYPE,
              (const void **)&text,len);

        sys->Unlock();
    }
    
    printf("%s\n", text);
    return 0;
}
