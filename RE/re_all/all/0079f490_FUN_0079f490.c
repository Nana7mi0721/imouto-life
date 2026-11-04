
void FUN_0079f490(uint *param_1,int *param_2,short *param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  short *psVar4;
  uint uVar5;
  int local_8;
  
  uVar1 = 0;
  iVar2 = 0;
  iVar3 = 0;
  param_4 = param_4 + -1;
  if (0 < param_4) {
    psVar4 = param_3;
    do {
      uVar1 = (int)psVar4[1] * (int)psVar4[1] + uVar1 + (int)*psVar4 * (int)*psVar4;
      if ((int)uVar1 < 0) {
        iVar3 = iVar3 + 2;
        local_8 = 2;
        uVar1 = uVar1 >> 2;
        iVar2 = 2;
        if (iVar3 < param_4) {
          uVar5 = (param_4 - iVar3) + 1U >> 1;
          psVar4 = param_3 + iVar3;
          iVar3 = iVar3 + uVar5 * 2;
          do {
            uVar1 = uVar1 + ((uint)((int)psVar4[1] * (int)psVar4[1] + (int)*psVar4 * (int)*psVar4)
                            >> ((byte)local_8 & 0x1f));
            if ((int)uVar1 < 0) {
              uVar1 = uVar1 >> 2;
              local_8 = local_8 + 2;
            }
            psVar4 = psVar4 + 2;
            uVar5 = uVar5 - 1;
            iVar2 = local_8;
          } while (uVar5 != 0);
        }
        break;
      }
      iVar3 = iVar3 + 2;
      psVar4 = psVar4 + 2;
    } while (iVar3 < param_4);
  }
  if (iVar3 == param_4) {
    uVar1 = uVar1 + ((int)param_3[iVar3] * (int)param_3[iVar3] >> ((byte)iVar2 & 0x1f));
  }
  if ((uVar1 & 0xc0000000) != 0) {
    uVar1 = uVar1 >> 2;
    iVar2 = iVar2 + 2;
  }
  *param_2 = iVar2;
  *param_1 = uVar1;
  return;
}

