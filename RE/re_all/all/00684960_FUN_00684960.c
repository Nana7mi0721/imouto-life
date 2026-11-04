
void FUN_00684960(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  
  iVar4 = *(int *)(param_1 + 0x188);
  uVar5 = *(int *)(param_1 + 0x30) * iVar4;
  uVar1 = *(uint *)(param_1 + 0x34);
  if (uVar1 < uVar5) {
    if (uVar1 * 2 < uVar5) {
      if (uVar1 * 3 < uVar5) {
        if (uVar1 * 4 < uVar5) {
          if (uVar1 * 5 < uVar5) {
            if (uVar1 * 6 < uVar5) {
              if (uVar1 * 7 < uVar5) {
                if (uVar1 * 8 < uVar5) {
                  if (uVar1 * 9 < uVar5) {
                    if (uVar1 * 10 < uVar5) {
                      if (uVar1 * 0xb < uVar5) {
                        if (uVar1 * 0xc < uVar5) {
                          if (uVar1 * 0xd < uVar5) {
                            if (uVar1 * 0xe < uVar5) {
                              if (uVar1 * 0xf < uVar5) {
                                uVar2 = FUN_006848b0(*(int *)(param_1 + 0x1c) << 4,iVar4);
                                *(undefined4 *)(param_1 + 0x5c) = uVar2;
                                uVar2 = FUN_006848b0(*(int *)(param_1 + 0x20) << 4,
                                                     *(undefined4 *)(param_1 + 0x188));
                                *(undefined4 *)(param_1 + 0x60) = uVar2;
                                uVar2 = 0x10;
                              }
                              else {
                                uVar2 = FUN_006848b0(*(int *)(param_1 + 0x1c) * 0xf,iVar4);
                                *(undefined4 *)(param_1 + 0x5c) = uVar2;
                                uVar2 = FUN_006848b0(*(int *)(param_1 + 0x20) * 0xf,
                                                     *(undefined4 *)(param_1 + 0x188));
                                *(undefined4 *)(param_1 + 0x60) = uVar2;
                                uVar2 = 0xf;
                              }
                            }
                            else {
                              uVar2 = FUN_006848b0(*(int *)(param_1 + 0x1c) * 0xe,iVar4);
                              *(undefined4 *)(param_1 + 0x5c) = uVar2;
                              uVar2 = FUN_006848b0(*(int *)(param_1 + 0x20) * 0xe,
                                                   *(undefined4 *)(param_1 + 0x188));
                              *(undefined4 *)(param_1 + 0x60) = uVar2;
                              uVar2 = 0xe;
                            }
                          }
                          else {
                            uVar2 = FUN_006848b0(*(int *)(param_1 + 0x1c) * 0xd,iVar4);
                            *(undefined4 *)(param_1 + 0x5c) = uVar2;
                            uVar2 = FUN_006848b0(*(int *)(param_1 + 0x20) * 0xd,
                                                 *(undefined4 *)(param_1 + 0x188));
                            *(undefined4 *)(param_1 + 0x60) = uVar2;
                            uVar2 = 0xd;
                          }
                        }
                        else {
                          uVar2 = FUN_006848b0(*(int *)(param_1 + 0x1c) * 0xc,iVar4);
                          *(undefined4 *)(param_1 + 0x5c) = uVar2;
                          uVar2 = FUN_006848b0(*(int *)(param_1 + 0x20) * 0xc,
                                               *(undefined4 *)(param_1 + 0x188));
                          *(undefined4 *)(param_1 + 0x60) = uVar2;
                          uVar2 = 0xc;
                        }
                      }
                      else {
                        uVar2 = FUN_006848b0(*(int *)(param_1 + 0x1c) * 0xb,iVar4);
                        *(undefined4 *)(param_1 + 0x5c) = uVar2;
                        uVar2 = FUN_006848b0(*(int *)(param_1 + 0x20) * 0xb,
                                             *(undefined4 *)(param_1 + 0x188));
                        *(undefined4 *)(param_1 + 0x60) = uVar2;
                        uVar2 = 0xb;
                      }
                    }
                    else {
                      uVar2 = FUN_006848b0(*(int *)(param_1 + 0x1c) * 10,iVar4);
                      *(undefined4 *)(param_1 + 0x5c) = uVar2;
                      uVar2 = FUN_006848b0(*(int *)(param_1 + 0x20) * 10,
                                           *(undefined4 *)(param_1 + 0x188));
                      *(undefined4 *)(param_1 + 0x60) = uVar2;
                      uVar2 = 10;
                    }
                  }
                  else {
                    uVar2 = FUN_006848b0(*(int *)(param_1 + 0x1c) * 9,iVar4);
                    *(undefined4 *)(param_1 + 0x5c) = uVar2;
                    uVar2 = FUN_006848b0(*(int *)(param_1 + 0x20) * 9,
                                         *(undefined4 *)(param_1 + 0x188));
                    *(undefined4 *)(param_1 + 0x60) = uVar2;
                    uVar2 = 9;
                  }
                }
                else {
                  uVar2 = FUN_006848b0(*(int *)(param_1 + 0x1c) << 3,iVar4);
                  *(undefined4 *)(param_1 + 0x5c) = uVar2;
                  uVar2 = FUN_006848b0(*(int *)(param_1 + 0x20) << 3,
                                       *(undefined4 *)(param_1 + 0x188));
                  *(undefined4 *)(param_1 + 0x60) = uVar2;
                  uVar2 = 8;
                }
              }
              else {
                uVar2 = FUN_006848b0(*(int *)(param_1 + 0x1c) * 7,iVar4);
                *(undefined4 *)(param_1 + 0x5c) = uVar2;
                uVar2 = FUN_006848b0(*(int *)(param_1 + 0x20) * 7,*(undefined4 *)(param_1 + 0x188));
                *(undefined4 *)(param_1 + 0x60) = uVar2;
                uVar2 = 7;
              }
            }
            else {
              uVar2 = FUN_006848b0(*(int *)(param_1 + 0x1c) * 6,iVar4);
              *(undefined4 *)(param_1 + 0x5c) = uVar2;
              uVar2 = FUN_006848b0(*(int *)(param_1 + 0x20) * 6,*(undefined4 *)(param_1 + 0x188));
              *(undefined4 *)(param_1 + 0x60) = uVar2;
              uVar2 = 6;
            }
          }
          else {
            uVar2 = FUN_006848b0(*(int *)(param_1 + 0x1c) * 5,iVar4);
            *(undefined4 *)(param_1 + 0x5c) = uVar2;
            uVar2 = FUN_006848b0(*(int *)(param_1 + 0x20) * 5,*(undefined4 *)(param_1 + 0x188));
            *(undefined4 *)(param_1 + 0x60) = uVar2;
            uVar2 = 5;
          }
        }
        else {
          uVar2 = FUN_006848b0(*(int *)(param_1 + 0x1c) << 2,iVar4);
          *(undefined4 *)(param_1 + 0x5c) = uVar2;
          uVar2 = FUN_006848b0(*(int *)(param_1 + 0x20) << 2,*(undefined4 *)(param_1 + 0x188));
          *(undefined4 *)(param_1 + 0x60) = uVar2;
          uVar2 = 4;
        }
      }
      else {
        uVar2 = FUN_006848b0(*(int *)(param_1 + 0x1c) * 3,iVar4);
        *(undefined4 *)(param_1 + 0x5c) = uVar2;
        uVar2 = FUN_006848b0(*(int *)(param_1 + 0x20) * 3,*(undefined4 *)(param_1 + 0x188));
        *(undefined4 *)(param_1 + 0x60) = uVar2;
        uVar2 = 3;
      }
    }
    else {
      uVar2 = FUN_006848b0(*(int *)(param_1 + 0x1c) << 1,iVar4);
      *(undefined4 *)(param_1 + 0x5c) = uVar2;
      uVar2 = FUN_006848b0(*(int *)(param_1 + 0x20) << 1,*(undefined4 *)(param_1 + 0x188));
      *(undefined4 *)(param_1 + 0x60) = uVar2;
      uVar2 = 2;
    }
  }
  else {
    uVar2 = FUN_006848b0(*(undefined4 *)(param_1 + 0x1c),iVar4);
    *(undefined4 *)(param_1 + 0x5c) = uVar2;
    uVar2 = FUN_006848b0(*(undefined4 *)(param_1 + 0x20),*(undefined4 *)(param_1 + 0x188));
    *(undefined4 *)(param_1 + 0x60) = uVar2;
    uVar2 = 1;
  }
  iVar4 = 0;
  *(undefined4 *)(param_1 + 0x120) = uVar2;
  *(undefined4 *)(param_1 + 0x124) = uVar2;
  if (0 < *(int *)(param_1 + 0x24)) {
    puVar3 = (undefined4 *)(*(int *)(param_1 + 0xc4) + 0x28);
    do {
      iVar4 = iVar4 + 1;
      puVar3[-1] = *(undefined4 *)(param_1 + 0x120);
      *puVar3 = *(undefined4 *)(param_1 + 0x124);
      puVar3 = puVar3 + 0x16;
    } while (iVar4 < *(int *)(param_1 + 0x24));
  }
  return;
}

