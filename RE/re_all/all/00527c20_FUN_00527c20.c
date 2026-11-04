
int FUN_00527c20(undefined4 param_1,undefined4 param_2,int param_3,float param_4,int param_5,
                float param_6,int param_7,float param_8,int param_9,float param_10,uint param_11,
                int param_12)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  if (param_12 == 0) {
    if (((((DAT_00cc47d0 != 0) && (-1 < (int)param_11)) && ((param_11 & 0x7c000000) == DAT_00cc47f8)
         ) && (((int)(param_11 & 0xffff) < DAT_00cc4800 &&
               (piVar4 = *(int **)(DAT_00cc47d4 + (param_11 & 0xffff) * 4), piVar4 != (int *)0x0))))
       && ((*piVar4 * 0x10000 == (param_11 & 0x3ff0000) && (piVar4[4] == 0)))) goto LAB_00527cc8;
  }
  else if ((((DAT_00cc47d0 != 0) && (-1 < (int)param_11)) &&
           ((param_11 & 0x7c000000) == DAT_00cc47f8)) &&
          ((((int)(param_11 & 0xffff) < DAT_00cc4800 &&
            (piVar4 = *(int **)(DAT_00cc47d4 + (param_11 & 0xffff) * 4), piVar4 != (int *)0x0)) &&
           (*piVar4 * 0x10000 == (param_11 & 0x3ff0000))))) {
LAB_00527cc8:
    if ((((-1 < param_3) && (-1 < param_5)) &&
        ((iVar3 = piVar4[0x18], param_3 < iVar3 &&
         ((iVar2 = piVar4[0x19], param_5 < iVar2 && (0.0 <= param_4)))))) &&
       ((0.0 <= param_6 &&
        ((fVar1 = (float)piVar4[0x1a],
         (NAN(fVar1) || NAN(param_4)) || fVar1 < param_4 == (fVar1 == param_4) &&
         (fVar1 = (float)piVar4[0x1b],
         (NAN(fVar1) || NAN(param_6)) || fVar1 < param_6 == (fVar1 == param_6))))))) {
      if (iVar3 < param_3 + param_7) {
        param_7 = iVar3 - param_3;
      }
      if ((float)piVar4[0x1a] < param_4 + param_8) {
        param_8 = (float)piVar4[0x1a] - param_4;
      }
      if (iVar2 < param_5 + param_9) {
        param_9 = iVar2 - param_5;
      }
      if ((float)piVar4[0x1b] < param_6 + param_10) {
        param_10 = (float)piVar4[0x1b] - param_6;
      }
      iVar3 = FUN_00527830(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                           param_10,param_11,param_12);
      return (iVar3 != -1) - 1;
    }
    return -1;
  }
  return -1;
}

