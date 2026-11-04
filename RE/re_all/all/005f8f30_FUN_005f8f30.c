
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_005f8f30(int param_1,short *param_2,int param_3,int param_4,int param_5,int param_6,
                 undefined4 *param_7)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  float *pfVar8;
  short *psVar9;
  uint local_c;
  int local_8;
  
  iVar1 = FUN_0060b400();
  if (*(int *)(param_1 + 0x58) < 2) {
    return 0xffffff7d;
  }
  do {
    if ((*(int *)(param_1 + 0x58) == 4) &&
       (local_c = FUN_006ad4e0(param_1 + 0x1e0,&local_8), local_c != 0)) {
      if ((int)local_c < 1) {
        return local_c;
      }
      iVar3 = FUN_006ab580(param_1,0xffffffff);
      iVar3 = *(int *)(iVar3 + 4);
      iVar6 = iVar3 * param_5;
      uVar2 = param_3 / iVar6;
      if ((int)uVar2 < (int)local_c) {
        local_c = uVar2;
      }
      if ((int)local_c < 1) {
        return 0xffffff7d;
      }
      if (param_5 == 1) {
        iVar1 = 0;
        if (0 < (int)local_c) {
          do {
            iVar4 = 0;
            if (0 < iVar3) {
              do {
                iVar7 = (int)ROUND(*(float *)(*(int *)(local_8 + iVar4 * 4) + iVar1 * 4) *
                                   _DAT_00802e14);
                if (iVar7 < 0x80) {
                  if (iVar7 < -0x80) {
                    iVar7 = -0x80;
                  }
                }
                else {
                  iVar7 = 0x7f;
                }
                *(byte *)param_2 = (-(param_6 != 0) & 0x80U) + 0x80 + (char)iVar7;
                param_2 = (short *)((int)param_2 + 1);
                iVar4 = iVar4 + 1;
              } while (iVar4 < iVar3);
            }
            iVar1 = iVar1 + 1;
          } while (iVar1 < (int)local_c);
        }
      }
      else {
        iVar4 = (-(uint)(param_6 != 0) & 0xffff8000) + 0x8000;
        if (iVar1 == param_4) {
          if (param_6 == 0) {
            param_5 = 0;
            if (0 < iVar3) {
              do {
                pfVar8 = *(float **)(local_8 + param_5 * 4);
                if (0 < (int)local_c) {
                  psVar9 = param_2;
                  uVar2 = local_c;
                  do {
                    iVar1 = (int)ROUND(*pfVar8 * _DAT_00802e10);
                    if (iVar1 < 0x8000) {
                      if (iVar1 < -0x8000) {
                        iVar1 = -0x8000;
                      }
                    }
                    else {
                      iVar1 = 0x7fff;
                    }
                    pfVar8 = pfVar8 + 1;
                    *psVar9 = (short)iVar1 + -0x8000;
                    psVar9 = psVar9 + iVar3;
                    uVar2 = uVar2 - 1;
                  } while (uVar2 != 0);
                }
                param_5 = param_5 + 1;
                param_2 = param_2 + 1;
              } while (param_5 < iVar3);
            }
          }
          else {
            iVar1 = 0;
            if (0 < iVar3) {
              do {
                pfVar8 = *(float **)(local_8 + iVar1 * 4);
                if (0 < (int)local_c) {
                  psVar9 = param_2;
                  uVar2 = local_c;
                  do {
                    iVar4 = (int)ROUND(*pfVar8 * _DAT_00802e10);
                    if (iVar4 < 0x8000) {
                      if (iVar4 < -0x8000) {
                        iVar4 = -0x8000;
                      }
                    }
                    else {
                      iVar4 = 0x7fff;
                    }
                    *psVar9 = (short)iVar4;
                    psVar9 = psVar9 + iVar3;
                    pfVar8 = pfVar8 + 1;
                    uVar2 = uVar2 - 1;
                  } while (uVar2 != 0);
                }
                iVar1 = iVar1 + 1;
                param_2 = param_2 + 1;
              } while (iVar1 < iVar3);
            }
          }
        }
        else {
          iVar1 = 0;
          if (param_4 == 0) {
            param_5 = 0;
            if (0 < (int)local_c) {
              do {
                iVar1 = 0;
                if (0 < iVar3) {
                  do {
                    iVar7 = (int)ROUND(*(float *)(*(int *)(local_8 + iVar1 * 4) + param_5 * 4) *
                                       _DAT_00802e10);
                    if (iVar7 < 0x8000) {
                      if (iVar7 < -0x8000) {
                        iVar7 = -0x8000;
                      }
                    }
                    else {
                      iVar7 = 0x7fff;
                    }
                    iVar7 = iVar7 + iVar4;
                    *(char *)param_2 = (char)iVar7;
                    *(char *)((int)param_2 + 1) = (char)((uint)iVar7 >> 8);
                    param_2 = param_2 + 1;
                    iVar1 = iVar1 + 1;
                  } while (iVar1 < iVar3);
                }
                param_5 = param_5 + 1;
              } while (param_5 < (int)local_c);
            }
          }
          else if (0 < (int)local_c) {
            do {
              iVar7 = 0;
              if (0 < iVar3) {
                do {
                  iVar5 = (int)ROUND(*(float *)(*(int *)(local_8 + iVar7 * 4) + iVar1 * 4) *
                                     _DAT_00802e10);
                  if (iVar5 < 0x8000) {
                    if (iVar5 < -0x8000) {
                      iVar5 = -0x8000;
                    }
                  }
                  else {
                    iVar5 = 0x7fff;
                  }
                  iVar5 = iVar5 + iVar4;
                  *(char *)param_2 = (char)((uint)iVar5 >> 8);
                  *(char *)((int)param_2 + 1) = (char)iVar5;
                  param_2 = param_2 + 1;
                  iVar7 = iVar7 + 1;
                } while (iVar7 < iVar3);
              }
              iVar1 = iVar1 + 1;
            } while (iVar1 < (int)local_c);
          }
        }
      }
      FUN_006ad540(param_1 + 0x1e0,local_c);
      uVar2 = *(uint *)(param_1 + 0x50);
      *(uint *)(param_1 + 0x50) = uVar2 + local_c;
      *(uint *)(param_1 + 0x54) =
           *(int *)(param_1 + 0x54) + ((int)local_c >> 0x1f) + (uint)CARRY4(uVar2,local_c);
      if (param_7 != (undefined4 *)0x0) {
        *param_7 = *(undefined4 *)(param_1 + 0x60);
      }
      return iVar6 * local_c;
    }
    uVar2 = FUN_005f9290(param_1,0,1,1);
    if (uVar2 == 0xfffffffe) {
      return 0;
    }
  } while (0 < (int)uVar2);
  return uVar2;
}

