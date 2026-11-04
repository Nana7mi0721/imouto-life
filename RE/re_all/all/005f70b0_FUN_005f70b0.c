
undefined4 FUN_005f70b0(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int *unaff_EBX;
  int *unaff_EBP;
  bool bVar6;
  int **ppiVar7;
  int *piVar8;
  int *piVar9;
  undefined *puVar10;
  int *local_120;
  int *piStack_11c;
  int *local_118;
  int *local_114;
  int *local_110;
  int *local_10c [2];
  int *local_104;
  undefined4 uStack_100;
  int iStack_fc;
  int local_f8;
  int iStack_f4;
  int *local_f0;
  int iStack_ec;
  int *piStack_e8;
  undefined4 local_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 local_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined1 local_54 [44];
  int aiStack_28 [6];
  short *psStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_007b221e;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_006034d0();
  local_4 = 0;
  FUN_006034d0();
  local_4._0_1_ = 1;
  FUN_006034d0();
  local_4 = CONCAT31(local_4._1_3_,2);
  local_f0 = (int *)(param_1 + 0x4a);
  local_f8 = 0;
  local_104 = (int *)0x0;
  local_118 = (int *)0x0;
  local_120 = (int *)0x0;
  local_110 = (int *)0x0;
  local_10c[0] = (int *)0x0;
  local_114 = (int *)0x0;
  FUN_0056d380(local_f0,0,0x10);
  (**(code **)(param_1 + 0x10))(*(undefined4 *)(param_1 + 0x24),0,0,2);
  iVar1 = (**(code **)(param_1 + 0xc))(*(undefined4 *)(param_1 + 0x24));
  iStack_f4 = iVar1;
  (**(code **)(param_1 + 0x10))(*(undefined4 *)(param_1 + 0x24),0,0,0);
  iVar2 = FUN_0056e030(iVar1,s_D__DxLib_Develop_Source_Library__00a058f8,0x844);
  iStack_ec = iVar2;
  if (iVar2 != 0) {
    (**(code **)(param_1 + 0x14))(iVar2,iVar1,1,*(undefined4 *)(param_1 + 0x24));
    local_f8 = FUN_0060a190(iVar2,iVar1,0,0xffffffff);
    if (local_f8 == 0) {
      puVar10 = &DAT_00a05d68;
    }
    else {
      local_9c = DAT_0085eb84;
      uStack_98 = DAT_0085eb88;
      uStack_94 = DAT_0085eb8c;
      uStack_90 = DAT_0085eb90;
      uStack_8c = DAT_0085ec54;
      uStack_88 = DAT_0085ec58;
      uStack_84 = DAT_0085ec5c;
      uStack_80 = DAT_0085ec60;
      piStack_11c = (int *)0x0;
      local_104 = (int *)FUN_0060a0a0(local_f8,&local_9c,&piStack_11c);
      if (local_104 == (int *)0x0) {
        puVar10 = &DAT_00a05d3c;
      }
      else {
        piVar5 = local_104 + 3;
        (**(code **)(*piVar5 + 4))(piVar5);
        iVar1 = (*DAT_00aba190)(&DAT_0085e864,0,1,&DAT_0085eae4,&piStack_11c);
        if (iVar1 < 0) {
          puVar10 = &DAT_00a05d10;
        }
        else {
          iVar1 = (*DAT_00aba190)(&DAT_0085e814,0,3,&DAT_0085ea44,&local_120);
          if (iVar1 < 0) {
            puVar10 = &DAT_00a05ce0;
          }
          else {
            piStack_11c = (int *)0x1;
            iVar1 = FUN_00609930(0,&piStack_11c);
            if (iVar1 == 0) {
              puVar10 = &DAT_00a05cb0;
            }
            else {
              uStack_e0 = DAT_0085eb78;
              local_e4 = DAT_0085eb74;
              uStack_dc = DAT_0085eb7c;
              uStack_d4 = DAT_0085ec24;
              uStack_d8 = DAT_0085eb80;
              uStack_d0 = DAT_0085ec28;
              uStack_c8 = DAT_0085ec30;
              piStack_e8 = (int *)(iVar1 + 0xa0);
              uStack_cc = DAT_0085ec2c;
              piStack_11c = (int *)(**(code **)(*piStack_e8 + 0xc))(piStack_e8,&local_e4);
              if (piStack_11c == (int *)0x0) {
                piStack_11c = (int *)(**(code **)(*local_120 + 0xc))
                                               (local_120,iVar1 + 0xc,u_SampleGrabber_00a05c58);
                if (piStack_11c == (int *)0x0) {
                  piStack_11c = (int *)(**(code **)(*local_120 + 0xc))
                                                 (local_120,piVar5,u_MemFile_00a05c10);
                  if (piStack_11c == (int *)0x0) {
                    iVar1 = (**(code **)(*local_104 + 0x1c))(0);
                    if (iVar1 == 0) {
                      iVar1 = 0;
                    }
                    else {
                      iVar1 = iVar1 + 0xc;
                    }
                    piStack_11c = (int *)(**(code **)(*unaff_EBX + 0x30))(unaff_EBX,iVar1);
                    if (piStack_11c == (int *)0x0) {
                      piStack_11c = (int *)(**(code **)(*local_120 + 0xc))
                                                     (local_120,local_118,u_File_Renderer_00a05ba0);
                      if (piStack_11c == (int *)0x0) {
                        piVar5 = &iStack_fc;
                        uStack_100 = 0;
                        piVar9 = local_120;
                        (**(code **)(*local_120 + 0x14))();
                        ppiVar7 = &local_110;
                        piVar8 = (int *)0x0;
                        iVar1 = (**(code **)(*local_104 + 0xc))(local_104,1);
                        while (iVar1 == 0) {
                          piVar3 = (int *)FUN_005f7020(local_120,0);
                          piVar4 = (int *)FUN_005f7020(local_120,1);
                          if (piVar3 != (int *)0x0) {
                            if ((piVar4 == (int *)0x0) &&
                               ((**(code **)(*piVar3 + 0x18))(piVar3,&local_118),
                               local_118 != (int *)0x0)) {
                              (**(code **)(*piVar9 + 0x24))(piVar9,local_118);
                              (*(code *)(*ppiVar7)[9])(ppiVar7,piVar3);
                              (**(code **)(*piVar3 + 8))(piVar3);
                              (**(code **)(*piVar5 + 8))(piVar5);
                              break;
                            }
                            (**(code **)(*piVar3 + 8))(piVar3);
                          }
                          if (piVar4 != (int *)0x0) {
                            (**(code **)(*piVar4 + 8))(piVar4);
                          }
                          (**(code **)(*local_120 + 8))(local_120);
                          iVar1 = (**(code **)(*local_118 + 0xc))(local_118,1,local_10c + -6,0);
                        }
                        (**(code **)(*local_114 + 8))(local_114);
                        piVar5 = (int *)FUN_005f7020(piVar5,0);
                        (**(code **)(*piVar8 + 0x2c))(piVar8,piStack_11c,piVar5);
                        (**(code **)(*unaff_EBP + 8))(unaff_EBP);
                        (**(code **)(*piVar5 + 8))(piVar5);
                        if (piStack_11c == (int *)0x0) {
                          FUN_0056d380(local_54,0,0x48);
                          piStack_11c = (int *)(**(code **)(*piStack_e8 + 0x10))
                                                         (piStack_e8,local_54);
                          if (piStack_11c == (int *)0x0) {
                            iVar1 = 4;
                            bVar6 = true;
                            piVar5 = aiStack_28;
                            piVar8 = &DAT_0085eb54;
                            do {
                              if (iVar1 == 0) break;
                              iVar1 = iVar1 + -1;
                              bVar6 = *piVar5 == *piVar8;
                              piVar5 = piVar5 + 1;
                              piVar8 = piVar8 + 1;
                            } while (bVar6);
                            if (bVar6) {
                              if (*psStack_10 == 1) {
                                *(undefined2 *)(param_1 + 0x48) = 0;
                                *(short *)(param_1 + 0x38) = *psStack_10;
                                *(short *)(param_1 + 0x3a) = psStack_10[1];
                                *(short *)(param_1 + 0x44) = psStack_10[6];
                                *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(psStack_10 + 2);
                                *(uint *)(param_1 + 0x40) =
                                     (uint)*(ushort *)(param_1 + 0x44) * *(int *)(psStack_10 + 2);
                                *(short *)(param_1 + 0x46) =
                                     (short)(((ulonglong)(ushort)psStack_10[6] << 3) /
                                            (ulonglong)(longlong)(int)(uint)(ushort)psStack_10[1]);
                                piStack_11c = (int *)(**(code **)(*piStack_e8 + 0x14))
                                                               (piStack_e8,&LAB_005f6f70,param_1);
                                piVar5 = local_f0;
                                if (piStack_11c == (int *)0x0) {
                                  local_f0[1] = iStack_f4 * 10;
                                  iVar1 = FUN_0056e030(iStack_f4 * 10,
                                                       s_D__DxLib_Develop_Source_Library__00a058f8,
                                                       0x902);
                                  *piVar5 = iVar1;
                                  if (iVar1 == 0) {
                                    puVar10 = &DAT_00a05a34;
                                  }
                                  else {
                                    piVar5[2] = 0;
                                    piStack_11c = (int *)(**(code **)*local_120)
                                                                   (local_120,&DAT_0085ea24,
                                                                    local_10c);
                                    if (piStack_11c == (int *)0x0) {
                                      (**(code **)(*local_10c[0] + 0x20))(local_10c[0],0);
                                      piStack_11c = (int *)(**(code **)*unaff_EBP)
                                                                     (unaff_EBP,&DAT_0085e9d4,
                                                                      &local_118);
                                      if (piStack_11c == (int *)0x0) {
                                        piStack_11c = (int *)(**(code **)*local_120)
                                                                       (local_120,&DAT_0085e9b4,
                                                                        &local_114);
                                        if (piStack_11c == (int *)0x0) {
                                          (**(code **)(*local_110 + 0x1c))(local_110);
                                          iVar1 = FUN_005501a0();
                                          while (iVar1 == 0) {
                                            iVar1 = (**(code **)(*local_114 + 0x24))
                                                              (local_114,100,&iStack_f4);
                                            if (iVar1 == 0) {
                                              if (iStack_f4 == 3) {
                                                puVar10 = &DAT_00a05980;
                                                goto LAB_005f76ab;
                                              }
                                              if (iStack_f4 == 1) {
                                                if (*piVar5 != 0) {
                                                  *(undefined4 *)(param_1 + 8) = 4;
                                                  *(undefined4 *)(param_1 + 0x450) =
                                                       *(undefined4 *)(param_1 + 0x40);
                                                  if (local_114 != (int *)0x0) {
                                                    (**(code **)(*local_114 + 8))(local_114);
                                                    local_114 = (int *)0x0;
                                                  }
                                                  if (local_10c[0] != (int *)0x0) {
                                                    (**(code **)(*local_10c[0] + 8))(local_10c[0]);
                                                    local_10c[0] = (int *)0x0;
                                                  }
                                                  if (local_110 != (int *)0x0) {
                                                    (**(code **)(*local_110 + 8))(local_110);
                                                    local_110 = (int *)0x0;
                                                  }
                                                  if (local_120 != (int *)0x0) {
                                                    (**(code **)(*local_120 + 8))(local_120);
                                                    local_120 = (int *)0x0;
                                                  }
                                                  if (local_118 != (int *)0x0) {
                                                    (**(code **)(*local_118 + 8))(local_118);
                                                    local_118 = (int *)0x0;
                                                  }
                                                  FUN_0060a200();
                                                  FUN_0060a180();
                                                  FUN_0056e1d0(iStack_ec);
                                                  local_4._0_1_ = 1;
                                                  FUN_006034c0();
                                                  local_4 = (uint)local_4._1_3_ << 8;
                                                  FUN_006034c0();
                                                  local_4 = 0xffffffff;
                                                  FUN_006034c0();
                                                  ExceptionList = pvStack_c;
                                                  return 0;
                                                }
                                                puVar10 = &DAT_00a0594c;
                                                goto LAB_005f76ab;
                                              }
                                            }
                                            iVar1 = FUN_005501a0();
                                          }
                                          puVar10 = &DAT_00a059a4;
                                        }
                                        else {
                                          puVar10 = &DAT_00a059c8;
                                        }
                                      }
                                      else {
                                        puVar10 = &DAT_00a059ec;
                                      }
                                    }
                                    else {
                                      puVar10 = &DAT_00a05a10;
                                    }
                                  }
                                }
                                else {
                                  puVar10 = &DAT_00a05a68;
                                }
                              }
                              else {
                                puVar10 = &DAT_00a05a8c;
                              }
                            }
                            else {
                              puVar10 = &DAT_00a05ab8;
                            }
                          }
                          else {
                            puVar10 = &DAT_00a05ae4;
                          }
                        }
                        else {
                          puVar10 = &DAT_00a05b2c;
                        }
                      }
                      else {
                        puVar10 = &DAT_00a05b68;
                      }
                    }
                    else {
                      puVar10 = &DAT_00a05bbc;
                    }
                  }
                  else {
                    puVar10 = &DAT_00a05bd8;
                  }
                }
                else {
                  puVar10 = &DAT_00a05c20;
                }
              }
              else {
                puVar10 = &DAT_00a05c74;
              }
            }
          }
        }
      }
    }
LAB_005f76ab:
    FUN_0056ba10(puVar10);
  }
  if (local_114 != (int *)0x0) {
    (**(code **)(*local_114 + 8))(local_114);
    local_114 = (int *)0x0;
  }
  if (local_10c[0] != (int *)0x0) {
    (**(code **)(*local_10c[0] + 8))(local_10c[0]);
    local_10c[0] = (int *)0x0;
  }
  if (local_110 != (int *)0x0) {
    (**(code **)(*local_110 + 8))(local_110);
    local_110 = (int *)0x0;
  }
  if (local_120 != (int *)0x0) {
    (**(code **)(*local_120 + 8))(local_120);
    local_120 = (int *)0x0;
  }
  if (local_118 != (int *)0x0) {
    (**(code **)(*local_118 + 8))(local_118);
    local_118 = (int *)0x0;
  }
  if (local_f8 != 0) {
    FUN_0060a200();
  }
  if (local_104 != (int *)0x0) {
    FUN_0060a180();
  }
  if (iStack_ec != 0) {
    FUN_0056e1d0(iStack_ec);
  }
  piVar5 = local_f0;
  if (*local_f0 != 0) {
    FUN_0056e1d0(*local_f0);
    *piVar5 = 0;
  }
  local_4._0_1_ = 1;
  FUN_006034c0();
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_006034c0();
  local_4 = 0xffffffff;
  FUN_006034c0();
  ExceptionList = pvStack_c;
  return 0xffffffff;
}

