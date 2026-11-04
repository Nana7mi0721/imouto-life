
undefined4 FUN_0057f470(void)

{
  undefined4 local_c;
  undefined4 local_8;
  
  if (DAT_00a834d8 == 1) {
    local_c = FUN_0050e7c0();
    local_8 = 0;
    (*DAT_00aba178)(DAT_00a834ec,0x806,5,&local_c);
    DAT_00a828d0 = 1;
    return 0;
  }
  if (DAT_00a828d0 == 1) {
    (*DAT_00aba178)(DAT_00a834ec,0x804,0,0);
    DAT_00a828d0 = 0;
  }
  return 0;
}

