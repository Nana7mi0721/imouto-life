
uint FUN_007a4670(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = param_1 * 2 + -1;
  if ((param_5 != 0) && (param_1 == 2)) {
    iVar3 = 2;
  }
  uVar1 = (iVar3 * param_3 + param_2) / iVar3;
  uVar2 = (param_2 - param_4) - 0x20;
  if ((int)uVar2 < (int)uVar1) {
    uVar1 = uVar2;
  }
  if ((int)uVar1 < 0x41) {
    if ((int)uVar1 < 4) {
      return 1;
    }
  }
  else {
    uVar1 = 0x40;
  }
  return ((int)(short)(&DAT_0083c57c)[uVar1 & 7] >> (0xeU - (char)((int)uVar1 >> 3) & 0x1f)) + 1U &
         0xfffffffe;
}

