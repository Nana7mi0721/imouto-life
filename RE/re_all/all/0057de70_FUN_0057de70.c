
undefined4 FUN_0057de70(void)

{
  DAT_00aa4fa8 = (HANDLE)0x0;
  if (1 < DAT_00a20bf4) {
    DAT_00aa4fa8 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,(LPTHREAD_START_ROUTINE)&LAB_0057d010,
                                (LPVOID)0x0,4,(LPDWORD)&DAT_00aa4fac);
    SetThreadPriority(DAT_00aa4fa8,0xf);
    ResumeThread(DAT_00aa4fa8);
  }
  if (DAT_00aa4fa0 == 0) {
    FUN_0056bb10(&PTR_LAB_007d96fc);
    return 0;
  }
  FUN_0056bfe0();
  FUN_0056bb10(&DAT_007d9734);
  return 0;
}

