
/* Library Function - Single Match
    ___sbh_heap_init
   
   Library: Visual Studio 2003 Release */

undefined4 ___sbh_heap_init(undefined4 param_1)

{
  DAT_00f48b48 = HeapAlloc(DAT_00f48b5c,0,0x140);
  if (DAT_00f48b48 == (LPVOID)0x0) {
    return 0;
  }
  DAT_00f48b40 = 0;
  DAT_00f48b44 = 0;
  DAT_00f48b50 = DAT_00f48b48;
  DAT_00f48b4c = param_1;
  DAT_00f48b54 = 0x10;
  return 1;
}

