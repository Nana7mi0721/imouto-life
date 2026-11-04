
void FUN_00672b20(int param_1,int param_2,undefined4 *param_3,uint param_4,undefined4 *param_5)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    if (param_3 != (undefined4 *)0x0) {
      FUN_00669290(param_1,param_2,0x2000,0);
      uVar1 = FUN_0066caf0(param_1,0x100);
      *(undefined4 *)(param_2 + 0x9c) = uVar1;
      *(undefined4 *)(param_1 + 0x1b4) = uVar1;
      if ((0 < (int)param_4) && ((int)param_4 < 0x101)) {
        puVar4 = *(undefined4 **)(param_2 + 0x9c);
        for (uVar3 = param_4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
          *puVar4 = *param_3;
          param_3 = param_3 + 1;
          puVar4 = puVar4 + 1;
        }
        for (uVar3 = param_4 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
          *(undefined1 *)puVar4 = *(undefined1 *)param_3;
          param_3 = (undefined4 *)((int)param_3 + 1);
          puVar4 = (undefined4 *)((int)puVar4 + 1);
        }
      }
    }
    if (param_5 != (undefined4 *)0x0) {
      iVar2 = 1 << (*(byte *)(param_2 + 0x18) & 0x1f);
      if (((*(char *)(param_2 + 0x19) == '\0') && (iVar2 < (int)(uint)*(ushort *)(param_5 + 2))) ||
         ((*(char *)(param_2 + 0x19) == '\x02' &&
          (((iVar2 < (int)(uint)*(ushort *)((int)param_5 + 2) ||
            (iVar2 < (int)(uint)*(ushort *)(param_5 + 1))) ||
           (iVar2 < (int)(uint)*(ushort *)((int)param_5 + 6))))))) {
        FUN_006687b0(param_1,s_tRNS_chunk_has_out_of_range_samp_00a0cc30);
      }
      *(undefined4 *)(param_2 + 0xa0) = *param_5;
      *(undefined4 *)(param_2 + 0xa4) = param_5[1];
      *(undefined2 *)(param_2 + 0xa8) = *(undefined2 *)(param_5 + 2);
      if (param_4 == 0) {
        param_4 = 1;
      }
    }
    *(short *)(param_2 + 0x16) = (short)param_4;
    if (param_4 != 0) {
      *(uint *)(param_2 + 8) = *(uint *)(param_2 + 8) | 0x10;
      *(uint *)(param_2 + 0xe8) = *(uint *)(param_2 + 0xe8) | 0x2000;
    }
  }
  return;
}

