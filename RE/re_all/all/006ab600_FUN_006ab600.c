
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_006ab600(int param_1,short *param_2,int param_3,int param_4,int param_5,int param_6,
                undefined4 *param_7,code *param_8,undefined4 param_9)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  float *pfVar9;
  short *psVar10;
  int local_c;
  int local_8;
  
  iVar3 = FUN_0060b400();
  if (*(int *)(param_1 + 0x58) < 2) {
    return -0x83;
  }
  do {
    if ((*(int *)(param_1 + 0x58) == 4) &&
       (local_c = FUN_006ad4e0(param_1 + 0x1e0,&local_8), local_c != 0)) {
      if (local_c < 1) {
        return local_c;
      }
      iVar4 = FUN_006ab580(param_1,0xffffffff);
      iVar4 = *(int *)(iVar4 + 4);
      iVar5 = iVar4 * param_5;
      param_3 = param_3 / iVar5;
      if (param_3 < local_c) {
        local_c = param_3;
      }
      if (local_c < 1) {
        return -0x83;
      }
      if (param_8 != (code *)0x0) {
        (*param_8)(local_8,iVar4,local_c,param_9);
      }
      if (param_5 == 1) {
        iVar3 = 0;
        if (0 < local_c) {
          do {
            iVar6 = 0;
            if (0 < iVar4) {
              do {
                iVar8 = (int)ROUND(*(float *)(*(int *)(local_8 + iVar6 * 4) + iVar3 * 4) *
                                   _DAT_00802e14);
                if (iVar8 < 0x80) {
                  if (iVar8 < -0x80) {
                    iVar8 = -0x80;
                  }
                }
                else {
                  iVar8 = 0x7f;
                }
                *(byte *)param_2 = (-(param_6 != 0) & 0x80U) + 0x80 + (char)iVar8;
                param_2 = (short *)((int)param_2 + 1);
                iVar6 = iVar6 + 1;
              } while (iVar6 < iVar4);
            }
            iVar3 = iVar3 + 1;
          } while (iVar3 < local_c);
        }
      }
      else {
        iVar6 = (-(uint)(param_6 != 0) & 0xffff8000) + 0x8000;
        if (iVar3 == param_4) {
          if (param_6 == 0) {
            param_5 = 0;
            if (0 < iVar4) {
              do {
                pfVar9 = *(float **)(local_8 + param_5 * 4);
                if (0 < local_c) {
                  psVar10 = param_2;
                  iVar3 = local_c;
                  do {
                    iVar6 = (int)ROUND(*pfVar9 * _DAT_00802e10);
                    if (iVar6 < 0x8000) {
                      if (iVar6 < -0x8000) {
                        iVar6 = -0x8000;
                      }
                    }
                    else {
                      iVar6 = 0x7fff;
                    }
                    pfVar9 = pfVar9 + 1;
                    *psVar10 = (short)iVar6 + -0x8000;
                    psVar10 = psVar10 + iVar4;
                    iVar3 = iVar3 + -1;
                  } while (iVar3 != 0);
                }
                param_5 = param_5 + 1;
                param_2 = param_2 + 1;
              } while (param_5 < iVar4);
            }
          }
          else {
            param_5 = 0;
            if (0 < iVar4) {
              do {
                pfVar9 = *(float **)(local_8 + param_5 * 4);
                if (0 < local_c) {
                  psVar10 = param_2;
                  iVar3 = local_c;
                  do {
                    iVar6 = (int)ROUND(*pfVar9 * _DAT_00802e10);
                    if (iVar6 < 0x8000) {
                      if (iVar6 < -0x8000) {
                        iVar6 = -0x8000;
                      }
                    }
                    else {
                      iVar6 = 0x7fff;
                    }
                    *psVar10 = (short)iVar6;
                    psVar10 = psVar10 + iVar4;
                    pfVar9 = pfVar9 + 1;
                    iVar3 = iVar3 + -1;
                  } while (iVar3 != 0);
                }
                param_5 = param_5 + 1;
                param_2 = param_2 + 1;
              } while (param_5 < iVar4);
            }
          }
        }
        else {
          param_5 = 0;
          if (param_4 == 0) {
            if (0 < local_c) {
              do {
                iVar3 = 0;
                if (0 < iVar4) {
                  do {
                    iVar8 = (int)ROUND(*(float *)(*(int *)(local_8 + iVar3 * 4) + param_5 * 4) *
                                       _DAT_00802e10);
                    if (iVar8 < 0x8000) {
                      if (iVar8 < -0x8000) {
                        iVar8 = -0x8000;
                      }
                    }
                    else {
                      iVar8 = 0x7fff;
                    }
                    iVar8 = iVar8 + iVar6;
                    *(char *)param_2 = (char)iVar8;
                    *(char *)((int)param_2 + 1) = (char)((uint)iVar8 >> 8);
                    param_2 = param_2 + 1;
                    iVar3 = iVar3 + 1;
                  } while (iVar3 < iVar4);
                }
                param_5 = param_5 + 1;
              } while (param_5 < local_c);
            }
          }
          else if (0 < local_c) {
            do {
              iVar3 = 0;
              if (0 < iVar4) {
                do {
                  iVar8 = (int)ROUND(*(float *)(*(int *)(local_8 + iVar3 * 4) + param_5 * 4) *
                                     _DAT_00802e10);
                  if (iVar8 < 0x8000) {
                    if (iVar8 < -0x8000) {
                      iVar8 = -0x8000;
                    }
                  }
                  else {
                    iVar8 = 0x7fff;
                  }
                  iVar8 = iVar8 + iVar6;
                  *(char *)param_2 = (char)((uint)iVar8 >> 8);
                  *(char *)((int)param_2 + 1) = (char)iVar8;
                  param_2 = param_2 + 1;
                  iVar3 = iVar3 + 1;
                } while (iVar3 < iVar4);
              }
              param_5 = param_5 + 1;
            } while (param_5 < local_c);
          }
        }
      }
      FUN_006ad540(param_1 + 0x1e0,local_c);
      bVar2 = FUN_006ac590(*(undefined4 *)(param_1 + 0x48));
      uVar7 = local_c << (bVar2 & 0x1f);
      uVar1 = *(uint *)(param_1 + 0x50);
      *(uint *)(param_1 + 0x50) = uVar1 + uVar7;
      *(uint *)(param_1 + 0x54) =
           *(int *)(param_1 + 0x54) + ((int)uVar7 >> 0x1f) + (uint)CARRY4(uVar1,uVar7);
      if (param_7 != (undefined4 *)0x0) {
        *param_7 = *(undefined4 *)(param_1 + 0x60);
      }
      return iVar5 * local_c;
    }
    iVar4 = FUN_006ab250(param_1,0,1,1);
    if (iVar4 == -2) {
      return 0;
    }
  } while (0 < iVar4);
  return iVar4;
}

