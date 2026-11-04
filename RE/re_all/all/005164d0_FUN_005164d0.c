
uint FUN_005164d0(int param_1,int param_2)

{
  uint uVar1;
  int *piVar2;
  
  if ((((-1 < param_1) && (-1 < param_2)) && (param_1 < DAT_00a381b4)) && (param_2 < DAT_00a381b8))
  {
    if (DAT_00a37d78 != 0) {
      uVar1 = FUN_005689a0(param_1,param_2);
      return uVar1;
    }
    if (((((DAT_00cc47d0 == 0) || ((int)DAT_00a38120 < 0)) ||
         (((DAT_00a38120 & 0x7c000000) != DAT_00cc47f8 ||
          ((DAT_00cc4800 <= (int)(DAT_00a38120 & 0xffff) ||
           (piVar2 = *(int **)(DAT_00cc47d4 + (DAT_00a38120 & 0xffff) * 4), piVar2 == (int *)0x0))))
         )) || (*piVar2 * 0x10000 != (DAT_00a38120 & 0x3ff0000))) || (piVar2[4] != 0)) {
      piVar2 = (int *)&DAT_00a37df8;
    }
    else {
      piVar2 = piVar2 + 0x22;
    }
    if (DAT_00a37e70 == 0x10) {
      return (uint)*(ushort *)(*(int *)(piVar2[5] + 0xc) * param_2 + piVar2[3] + param_1 * 2);
    }
    if (DAT_00a37e70 == 0x20) {
      return *(uint *)(*(int *)(piVar2[5] + 0xc) * param_2 + piVar2[3] + param_1 * 4);
    }
  }
  return 0xffffffff;
}

