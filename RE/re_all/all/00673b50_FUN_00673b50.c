
void FUN_00673b50(int param_1,int param_2,uint param_3)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  char *pcVar6;
  uint uVar7;
  undefined4 *puVar8;
  char *local_4f4;
  int local_4f0;
  int local_4ec;
  int local_4e8;
  undefined4 *local_4e4;
  uint local_4e0;
  char local_4dc [84];
  undefined4 local_488;
  undefined1 local_408;
  undefined1 uStack_407;
  undefined1 uStack_406;
  byte bStack_405;
  undefined1 local_400 [1024];
  
  local_4f4 = (char *)0x0;
  local_4e8 = 0;
  if ((*(uint *)(param_1 + 0x74) & 1) == 0) {
    FUN_00668a30(param_1,s_missing_IHDR_00a0ce1c);
  }
  else if ((*(uint *)(param_1 + 0x74) & 6) != 0) {
    FUN_00673140(param_1,param_3);
    FUN_00668b90(param_1,s_out_of_place_00a0cdb4);
    return;
  }
  if (param_3 < 9) {
    FUN_00673140(param_1,param_3);
    FUN_00668b90(param_1,s_too_short_00a0bf48);
    return;
  }
  if ((*(ushort *)(param_1 + 0x326) & 0x8000) != 0) {
    FUN_00673140(param_1,param_3);
    return;
  }
  if ((*(ushort *)(param_1 + 0x326) & 4) == 0) {
    uVar3 = 0x51;
    if (param_3 < 0x51) {
      uVar3 = param_3;
    }
    FUN_00673110(param_1,local_4dc,uVar3);
    param_3 = param_3 - uVar3;
    uVar7 = 0;
    do {
      if ((uVar3 <= uVar7) || (local_4dc[uVar7] == '\0')) break;
      uVar7 = uVar7 + 1;
    } while (uVar7 < 0x50);
    if ((uVar7 == 0) || (0x4f < uVar7)) {
      local_4f4 = s_bad_keyword_00a0ce78;
    }
    else {
      local_4e0 = uVar7 + 1;
      if ((local_4e0 < uVar3) && (local_4dc[uVar7 + 1] == '\0')) {
        iVar1 = FUN_006740d0(param_1,0x69434350);
        if (iVar1 == 0) {
          *(char **)(param_1 + 0x84) = local_4dc + uVar7 + 2;
          local_4f0 = 0x84;
          *(uint *)(param_1 + 0x88) = (uVar3 - uVar7) + -2;
          FUN_006741c0(param_1,local_400,0x400,&param_3,&local_488,&local_4f0,0);
          if (local_4f0 == 0) {
            iVar4 = (((CONCAT12(local_488._2_1_,CONCAT11(local_488._1_1_,(undefined1)local_488)) &
                      0xff) * 0x100 +
                     (CONCAT12(local_488._3_1_,CONCAT11(local_488._2_1_,local_488._1_1_)) & 0xff)) *
                     0x100 + (CONCAT11(local_488._3_1_,local_488._2_1_) & 0xff)) * 0x100 +
                    (uint)local_488._3_1_;
            local_4ec = iVar4;
            iVar1 = FUN_0066a4e0(param_1,param_1 + 0x2dc,local_4dc,iVar4);
            if (iVar1 != 0) {
              iVar1 = FUN_0066a510(param_1,param_1 + 0x2dc,local_4dc,iVar4,&local_488,
                                   *(undefined1 *)(param_1 + 0x157));
              if (iVar1 != 0) {
                iVar1 = (((CONCAT12(uStack_406,CONCAT11(uStack_407,local_408)) & 0xff) * 0x100 +
                         (CONCAT12(bStack_405,CONCAT11(uStack_406,uStack_407)) & 0xff)) * 0x100 +
                        (CONCAT11(bStack_405,uStack_406) & 0xff)) * 0x100 + (uint)bStack_405;
                local_4e4 = (undefined4 *)FUN_00674040(param_1,iVar4,2);
                if (local_4e4 == (undefined4 *)0x0) {
                  local_4f4 = s_out_of_memory_00a0ce9c;
                }
                else {
                  puVar5 = &local_488;
                  puVar8 = local_4e4;
                  for (iVar4 = 0x21; iVar4 != 0; iVar4 = iVar4 + -1) {
                    *puVar8 = *puVar5;
                    puVar5 = puVar5 + 1;
                    puVar8 = puVar8 + 1;
                  }
                  local_4f0 = iVar1 * 0xc;
                  FUN_006741c0(param_1,local_400,0x400,&param_3,local_4e4 + 0x21,&local_4f0,0);
                  puVar5 = local_4e4;
                  if (local_4f0 == 0) {
                    iVar4 = FUN_0066a850(param_1,param_1 + 0x2dc,local_4dc,local_4ec,local_4e4);
                    if (iVar4 != 0) {
                      local_4f0 = local_4ec + iVar1 * -0xc + -0x84;
                      FUN_006741c0(param_1,local_400,0x400,&param_3,puVar5 + iVar1 * 3 + 0x21,
                                   &local_4f0,1);
                      if ((param_3 == 0) || ((*(uint *)(param_1 + 0x78) & 0x100000) != 0)) {
                        if (local_4f0 == 0) {
                          if (param_3 != 0) {
                            FUN_00668b30(param_1,s_extra_compressed_data_00a0ceac);
                          }
                          FUN_00673140(param_1,param_3);
                          local_4e8 = 1;
                          FUN_0066a980(param_1,param_1 + 0x2dc,puVar5,
                                       *(undefined4 *)(param_1 + 0xb4));
                          if (param_2 == 0) {
LAB_00673f68:
                            *(undefined4 *)(param_1 + 0x80) = 0;
                            return;
                          }
                          FUN_00669290(param_1,param_2,0x10,0);
                          uVar3 = local_4e0;
                          pcVar2 = (char *)FUN_0066c990(param_1,local_4e0);
                          *(char **)(param_2 + 0x74) = pcVar2;
                          if (pcVar2 == (char *)0x0) {
                            *(byte *)(param_1 + 0x327) = *(byte *)(param_1 + 0x327) | 0x80;
                            local_4f4 = s_out_of_memory_00a0ce9c;
                          }
                          else {
                            pcVar6 = local_4dc;
                            for (uVar7 = uVar3 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
                              *(undefined4 *)pcVar2 = *(undefined4 *)pcVar6;
                              pcVar6 = pcVar6 + 4;
                              pcVar2 = pcVar2 + 4;
                            }
                            for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
                              *pcVar2 = *pcVar6;
                              pcVar6 = pcVar6 + 1;
                              pcVar2 = pcVar2 + 1;
                            }
                            *(undefined4 **)(param_2 + 0x78) = local_4e4;
                            *(int *)(param_2 + 0x7c) = local_4ec;
                            *(undefined4 *)(param_1 + 0x2b8) = 0;
                            *(uint *)(param_2 + 0xe8) = *(uint *)(param_2 + 0xe8) | 0x10;
                            *(uint *)(param_2 + 8) = *(uint *)(param_2 + 8) | 0x1000;
                          }
                          FUN_006699d0(param_1,param_2);
                          if (local_4f4 == (char *)0x0) goto LAB_00673f68;
                        }
                        else if (local_4f0 == 0) {
                          local_4f4 = *(char **)(param_1 + 0x9c);
                        }
                        else {
                          local_4f4 = s_truncated_00a0bd48;
                        }
                      }
                      else {
                        local_4f4 = s_extra_compressed_data_00a0ceac;
                      }
                    }
                  }
                  else {
                    local_4f4 = *(char **)(param_1 + 0x9c);
                  }
                }
              }
            }
          }
          else {
            local_4f4 = *(char **)(param_1 + 0x9c);
          }
          *(undefined4 *)(param_1 + 0x80) = 0;
          if (local_4e8 != 0) goto LAB_00673fd6;
        }
        else {
          local_4f4 = *(char **)(param_1 + 0x9c);
        }
      }
      else {
        local_4f4 = s_bad_compression_method_00a0ce84;
      }
    }
  }
  else {
    local_4f4 = s_too_many_profiles_00a0ce64;
  }
  FUN_00673140(param_1,param_3);
LAB_00673fd6:
  *(byte *)(param_1 + 0x327) = *(byte *)(param_1 + 0x327) | 0x80;
  FUN_006699d0(param_1,param_2);
  if (local_4f4 != (char *)0x0) {
    FUN_00668b90(param_1,local_4f4);
  }
  return;
}

