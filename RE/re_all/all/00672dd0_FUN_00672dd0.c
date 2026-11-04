
void FUN_00672dd0(int param_1,int param_2,undefined4 *param_3,int param_4)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  if ((((param_1 != 0) && (param_2 != 0)) && (0 < param_4)) && (param_3 != (undefined4 *)0x0)) {
    iVar2 = FUN_0066ca40(param_1,*(undefined4 *)(param_2 + 0xec),*(undefined4 *)(param_2 + 0xf0),
                         param_4,0x14);
    if (iVar2 == 0) {
      FUN_00668bc0(param_1,s_too_many_unknown_chunks_00a0cccc,1);
      return;
    }
    FUN_0066cb60(param_1,*(undefined4 *)(param_2 + 0xec));
    *(uint *)(param_2 + 0xe8) = *(uint *)(param_2 + 0xe8) | 0x200;
    *(int *)(param_2 + 0xec) = iVar2;
    puVar5 = (undefined4 *)(iVar2 + *(int *)(param_2 + 0xf0) * 0x14);
    do {
      *puVar5 = *param_3;
      *(undefined1 *)(puVar5 + 1) = *(undefined1 *)(param_3 + 1);
      *(undefined1 *)(puVar5 + 1) = 0;
      uVar1 = FUN_00672f20(param_1,*(undefined1 *)(param_3 + 4));
      *(undefined1 *)(puVar5 + 4) = uVar1;
      if (param_3[3] == 0) {
        puVar5[2] = 0;
        puVar5[3] = 0;
LAB_00672ef2:
        puVar5 = puVar5 + 5;
        *(int *)(param_2 + 0xf0) = *(int *)(param_2 + 0xf0) + 1;
      }
      else {
        iVar2 = FUN_0066c990(param_1,param_3[3]);
        puVar5[2] = iVar2;
        if (iVar2 != 0) {
          uVar4 = param_3[3];
          puVar6 = (undefined4 *)param_3[2];
          puVar7 = (undefined4 *)puVar5[2];
          for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
            *puVar7 = *puVar6;
            puVar6 = puVar6 + 1;
            puVar7 = puVar7 + 1;
          }
          for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
            *(undefined1 *)puVar7 = *(undefined1 *)puVar6;
            puVar6 = (undefined4 *)((int)puVar6 + 1);
            puVar7 = (undefined4 *)((int)puVar7 + 1);
          }
          puVar5[3] = param_3[3];
          goto LAB_00672ef2;
        }
        FUN_00668bc0(param_1,s_unknown_chunk__out_of_memory_00a0ccac,1);
      }
      param_3 = param_3 + 5;
      param_4 = param_4 + -1;
    } while (param_4 != 0);
  }
  return;
}

