
int FUN_006529c0(int param_1,undefined4 param_2)

{
  undefined8 uVar1;
  
  uVar1 = FUN_006527d0(param_1,param_2);
  if ((int)uVar1 >> 0x1f == (int)((ulonglong)uVar1 >> 0x20)) {
    return (int)uVar1;
  }
  FUN_006512e0(*(undefined4 *)(param_1 + 0x274),"TIFFVStripSize",s_Integer_overflow_00a06c8c);
  return 0;
}

