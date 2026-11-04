
undefined4
FUN_00527830(uint param_1,undefined4 param_2,int param_3,float param_4,int param_5,float param_6,
            int param_7,int param_8,int param_9,int param_10,uint param_11,int param_12)

{
  float fVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  
  if (param_12 == 0) {
    if (((DAT_00cc47d0 != 0) && (-1 < (int)param_1)) && ((param_1 & 0x7c000000) == DAT_00cc47f8)) {
      if ((int)(param_1 & 0xffff) < DAT_00cc4800) {
        piVar3 = *(int **)(DAT_00cc47d4 + (param_1 & 0xffff) * 4);
        if (((((piVar3 != (int *)0x0) && (*piVar3 * 0x10000 == (param_1 & 0x3ff0000))) &&
             ((piVar3[4] == 0 && ((-1 < (int)param_11 && ((param_11 & 0x7c000000) == DAT_00cc47f8)))
              ))) && ((int)(param_11 & 0xffff) < DAT_00cc4800)) &&
           (((piVar4 = *(int **)(DAT_00cc47d4 + (param_11 & 0xffff) * 4), piVar4 != (int *)0x0 &&
             (*piVar4 * 0x10000 == (param_11 & 0x3ff0000))) && (piVar4[4] == 0))))
        goto LAB_00527978;
      }
    }
  }
  else if (((DAT_00cc47d0 != 0) && (-1 < (int)param_1)) && ((param_1 & 0x7c000000) == DAT_00cc47f8))
  {
    if ((int)(param_1 & 0xffff) < DAT_00cc4800) {
      piVar3 = *(int **)(DAT_00cc47d4 + (param_1 & 0xffff) * 4);
      if (((piVar3 != (int *)0x0) && (*piVar3 * 0x10000 == (param_1 & 0x3ff0000))) &&
         ((-1 < (int)param_11 &&
          (((((param_11 & 0x7c000000) == DAT_00cc47f8 && ((int)(param_11 & 0xffff) < DAT_00cc4800))
            && (piVar4 = *(int **)(DAT_00cc47d4 + (param_11 & 0xffff) * 4), piVar4 != (int *)0x0))
           && (*piVar4 * 0x10000 == (param_11 & 0x3ff0000))))))) {
LAB_00527978:
        piVar2 = (int *)piVar4[0x13];
        piVar3[0x13] = (int)piVar2;
        *piVar2 = *piVar2 + 1;
        FUN_00523730(param_1,0,0,0,param_11,param_12);
        piVar3[0xf] = piVar4[0xf] + param_3;
        piVar3[0x11] = (int)(param_4 + (float)piVar4[0x11]);
        piVar3[0x10] = piVar4[0x10] + param_5;
        piVar3[0x12] = (int)(param_6 + (float)piVar4[0x12]);
        piVar3[0x14] = piVar4[0x14] + param_3;
        piVar3[0x16] = (int)((float)piVar4[0x16] + param_4);
        piVar3[0x15] = piVar4[0x15] + param_5;
        fVar1 = (float)piVar4[0x17];
        piVar3[0x18] = param_7;
        piVar3[0x17] = (int)(param_6 + fVar1);
        piVar3[0x19] = param_9;
        piVar3[0x1a] = param_8;
        piVar3[0x1b] = param_10;
        piVar3[0x20] = piVar4[0x20];
        FUN_00517880(param_1,param_2,param_12);
        return 0;
      }
    }
  }
  return 0xffffffff;
}

