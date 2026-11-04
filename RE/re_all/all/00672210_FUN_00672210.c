
void FUN_00672210(int param_1,undefined4 *param_2,char *param_3,undefined4 param_4,
                 undefined4 param_5,int param_6,int param_7,char *param_8,undefined4 *param_9)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  undefined4 *puVar10;
  char *pcVar11;
  int local_4;
  
  iVar2 = (int)param_2;
  if (((((param_1 != 0) && (param_2 != (undefined4 *)0x0)) && (param_3 != (char *)0x0)) &&
      (param_8 != (char *)0x0)) && ((param_7 < 1 || (param_9 != (undefined4 *)0x0)))) {
    uVar7 = 0xffffffff;
    pcVar4 = param_3;
    do {
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    uVar7 = ~uVar7;
    if ((param_6 < 0) || (3 < param_6)) {
      FUN_00668620(param_1,s_Invalid_pCAL_equation_type_00a0cb24);
    }
    if ((param_7 < 0) || (0xff < param_7)) {
      FUN_00668620(param_1,s_Invalid_pCAL_parameter_count_00a0cb04);
    }
    if (0 < param_7) {
      local_4 = param_7;
      param_2 = param_9;
      do {
        pcVar4 = (char *)*param_2;
        if (pcVar4 == (char *)0x0) {
LAB_006722d7:
          FUN_00668620(param_1,s_Invalid_format_for_pCAL_paramete_00a0cae0);
        }
        else {
          uVar8 = 0xffffffff;
          pcVar11 = pcVar4;
          do {
            if (uVar8 == 0) break;
            uVar8 = uVar8 - 1;
            cVar1 = *pcVar11;
            pcVar11 = pcVar11 + 1;
          } while (cVar1 != '\0');
          iVar3 = FUN_0066b0f0(pcVar4,~uVar8 - 1);
          if (iVar3 == 0) goto LAB_006722d7;
        }
        param_2 = param_2 + 1;
        local_4 = local_4 + -1;
      } while (local_4 != 0);
    }
    pcVar4 = (char *)FUN_0066cb30(param_1,uVar7);
    *(char **)(iVar2 + 0xd0) = pcVar4;
    if (pcVar4 == (char *)0x0) {
      FUN_006687b0(param_1,s_Insufficient_memory_for_pCAL_pur_00a0cab8);
      return;
    }
    for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
      *(undefined4 *)pcVar4 = *(undefined4 *)param_3;
      param_3 = param_3 + 4;
      pcVar4 = pcVar4 + 4;
    }
    for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
      *pcVar4 = *param_3;
      param_3 = param_3 + 1;
      pcVar4 = pcVar4 + 1;
    }
    *(undefined4 *)(iVar2 + 0xd4) = param_4;
    *(undefined4 *)(iVar2 + 0xd8) = param_5;
    *(undefined1 *)(iVar2 + 0xe5) = (undefined1)param_7;
    uVar7 = 0xffffffff;
    *(undefined1 *)(iVar2 + 0xe4) = (undefined1)param_6;
    pcVar4 = param_8;
    do {
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    uVar7 = ~uVar7;
    pcVar4 = (char *)FUN_0066cb30(param_1,uVar7);
    *(char **)(iVar2 + 0xdc) = pcVar4;
    if (pcVar4 == (char *)0x0) {
      FUN_006687b0(param_1,s_Insufficient_memory_for_pCAL_uni_00a0ca94);
      return;
    }
    for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
      *(undefined4 *)pcVar4 = *(undefined4 *)param_8;
      param_8 = param_8 + 4;
      pcVar4 = pcVar4 + 4;
    }
    for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
      *pcVar4 = *param_8;
      param_8 = param_8 + 1;
      pcVar4 = pcVar4 + 1;
    }
    uVar7 = param_7 * 4 + 4;
    puVar5 = (undefined4 *)FUN_0066cb30(param_1,uVar7);
    *(undefined4 **)(iVar2 + 0xe0) = puVar5;
    if (puVar5 == (undefined4 *)0x0) {
      FUN_006687b0(param_1,s_Insufficient_memory_for_pCAL_par_00a0ca70);
      return;
    }
    iVar3 = 0;
    for (uVar7 = uVar7 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
    for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
      *(undefined1 *)puVar5 = 0;
      puVar5 = (undefined4 *)((int)puVar5 + 1);
    }
    if (0 < param_7) {
      do {
        uVar7 = 0xffffffff;
        pcVar4 = (char *)param_9[iVar3];
        do {
          if (uVar7 == 0) break;
          uVar7 = uVar7 - 1;
          cVar1 = *pcVar4;
          pcVar4 = pcVar4 + 1;
        } while (cVar1 != '\0');
        uVar7 = ~uVar7;
        uVar6 = FUN_0066cb30(param_1,uVar7);
        *(undefined4 *)(*(int *)(iVar2 + 0xe0) + iVar3 * 4) = uVar6;
        puVar5 = *(undefined4 **)(*(int *)(iVar2 + 0xe0) + iVar3 * 4);
        if (puVar5 == (undefined4 *)0x0) {
          FUN_006687b0(param_1,s_Insufficient_memory_for_pCAL_par_00a0ca48);
          return;
        }
        puVar10 = (undefined4 *)param_9[iVar3];
        for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
          *puVar5 = *puVar10;
          puVar10 = puVar10 + 1;
          puVar5 = puVar5 + 1;
        }
        iVar3 = iVar3 + 1;
        for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
          *(undefined1 *)puVar5 = *(undefined1 *)puVar10;
          puVar10 = (undefined4 *)((int)puVar10 + 1);
          puVar5 = (undefined4 *)((int)puVar5 + 1);
        }
      } while (iVar3 < param_7);
    }
    *(uint *)(iVar2 + 8) = *(uint *)(iVar2 + 8) | 0x400;
    *(uint *)(iVar2 + 0xe8) = *(uint *)(iVar2 + 0xe8) | 0x80;
  }
  return;
}

