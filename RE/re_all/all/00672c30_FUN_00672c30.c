
void FUN_00672c30(int param_1,int param_2,int *param_3,int param_4)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  char *pcVar8;
  
  if ((((param_1 != 0) && (param_2 != 0)) && (0 < param_4)) && (param_3 != (int *)0x0)) {
    iVar2 = FUN_0066ca40(param_1,*(undefined4 *)(param_2 + 0xf4),*(undefined4 *)(param_2 + 0xf8),
                         param_4,0x10);
    if (iVar2 == 0) {
      FUN_00668bc0(param_1,s_too_many_sPLT_chunks_00a0cc94,1);
      return;
    }
    FUN_0066cb60(param_1,*(undefined4 *)(param_2 + 0xf4));
    *(int *)(param_2 + 0xf4) = iVar2;
    *(uint *)(param_2 + 0xe8) = *(uint *)(param_2 + 0xe8) | 0x20;
    puVar6 = (undefined4 *)(iVar2 + *(int *)(param_2 + 0xf8) * 0x10);
    do {
      if ((*param_3 == 0) || (param_3[2] == 0)) {
        FUN_00668a00(param_1,s_png_set_sPLT__invalid_sPLT_00a0cc78);
      }
      else {
        *(char *)(puVar6 + 1) = (char)param_3[1];
        uVar4 = 0xffffffff;
        pcVar8 = (char *)*param_3;
        do {
          if (uVar4 == 0) break;
          uVar4 = uVar4 - 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        uVar4 = ~uVar4;
        puVar3 = (undefined4 *)FUN_0066c990(param_1,uVar4);
        *puVar6 = puVar3;
        if (puVar3 == (undefined4 *)0x0) break;
        puVar7 = (undefined4 *)*param_3;
        for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
          *puVar3 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar3 = puVar3 + 1;
        }
        for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
          *(undefined1 *)puVar3 = *(undefined1 *)puVar7;
          puVar7 = (undefined4 *)((int)puVar7 + 1);
          puVar3 = (undefined4 *)((int)puVar3 + 1);
        }
        iVar2 = FUN_0066c9d0(param_1,param_3[3],10);
        puVar6[2] = iVar2;
        if (iVar2 == 0) {
          FUN_0066cb60(param_1,*puVar6);
          break;
        }
        puVar6[3] = param_3[3];
        iVar2 = param_3[3];
        puVar3 = (undefined4 *)param_3[2];
        puVar7 = (undefined4 *)puVar6[2];
        for (uVar4 = (uint)(iVar2 * 10) >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
          *puVar7 = *puVar3;
          puVar3 = puVar3 + 1;
          puVar7 = puVar7 + 1;
        }
        for (uVar4 = iVar2 * 10 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
          *(undefined1 *)puVar7 = *(undefined1 *)puVar3;
          puVar3 = (undefined4 *)((int)puVar3 + 1);
          puVar7 = (undefined4 *)((int)puVar7 + 1);
        }
        *(uint *)(param_2 + 8) = *(uint *)(param_2 + 8) | 0x2000;
        *(int *)(param_2 + 0xf8) = *(int *)(param_2 + 0xf8) + 1;
        puVar6 = puVar6 + 4;
      }
      param_3 = param_3 + 4;
      param_4 = param_4 + -1;
    } while (param_4 != 0);
    if (0 < param_4) {
      FUN_00668bc0(param_1,s_sPLT_out_of_memory_00a0cc64,1);
    }
  }
  return;
}

