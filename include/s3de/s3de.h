#ifndef _S3DE_H
#define _S3DE_H

typedef struct s3deWindow s3deWindow;

int s3deInit();

s3deWindow* s3deCreateWindow(int height, int width, const char* title);

int s3deWindowIsClosed(s3deWindow* p_s3deWindow);

void s3deRender(s3deWindow* p_s3deWindow);

void s3deTerminate(s3deWindow* p_s3deWindow);

#endif