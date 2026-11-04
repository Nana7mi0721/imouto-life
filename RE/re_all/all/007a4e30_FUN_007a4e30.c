
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007a4e30(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,undefined4 param_8,int param_9)

{
  float *pfVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int local_c;
  
  local_c = 0;
  do {
    if (param_2 < param_3) {
      piVar5 = (int *)(param_5 + param_2 * 4);
      iVar3 = param_2;
      do {
        if (param_7 < param_9) break;
        if ((*piVar5 < 8) && (*(int *)((param_6 - param_5) + (int)piVar5) == local_c)) {
          iVar4 = 0;
          do {
            iVar2 = FUN_007a2250(param_8,1);
            pfVar1 = (float *)(param_4 + (*(int *)(param_1 + 8) * iVar4 + iVar3) * 4);
            param_7 = param_7 + -1;
            iVar4 = iVar4 + 1;
            *pfVar1 = ((float)iVar2 - _DAT_007d589c) * (float)(1 << (0xdU - (char)*piVar5 & 0x1f)) *
                      _DAT_0083c7b4 + *pfVar1;
          } while (iVar4 < param_9);
        }
        iVar3 = iVar3 + 1;
        piVar5 = piVar5 + 1;
      } while (iVar3 < param_3);
    }
    local_c = local_c + 1;
    if (1 < local_c) {
      return;
    }
  } while( true );
}

