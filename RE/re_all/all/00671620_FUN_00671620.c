
void FUN_00671620(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 != 0) {
    if ((*(byte *)(param_1 + 0x74) & 4) == 0) {
      FUN_00668620(param_1,s_No_IDATs_written_into_file_00a0c8c0);
    }
    if ((int)(uint)*(ushort *)(param_1 + 0x148) < *(int *)(param_1 + 0x14c)) {
      FUN_00668960(param_1,s_Wrote_palette_index_exceeding_nu_00a0c894);
    }
    if (param_2 != 0) {
      if (((*(uint *)(param_2 + 8) & 0x200) != 0) && ((*(uint *)(param_1 + 0x74) & 0x200) == 0)) {
        FUN_006790b0(param_1,param_2 + 0x8c);
      }
      iVar3 = 0;
      if (0 < *(int *)(param_2 + 0x80)) {
        iVar4 = 0;
        do {
          iVar2 = *(int *)(*(int *)(param_2 + 0x88) + iVar4);
          iVar1 = *(int *)(param_2 + 0x88) + iVar4;
          if (iVar2 < 1) {
            if (iVar2 < 0) {
              if (iVar2 == -1) {
                FUN_006789a0(param_1,*(undefined4 *)(iVar1 + 4),*(undefined4 *)(iVar1 + 8),0);
                goto LAB_0067170d;
              }
            }
            else {
              FUN_00678a50(param_1,*(undefined4 *)(iVar1 + 4),*(undefined4 *)(iVar1 + 8),0,iVar2);
              *(undefined4 *)(*(int *)(param_2 + 0x88) + iVar4) = 0xfffffffe;
            }
          }
          else {
            FUN_00678b60(param_1,iVar2,*(undefined4 *)(iVar1 + 4),*(undefined4 *)(iVar1 + 0x14),
                         *(undefined4 *)(iVar1 + 0x18),*(undefined4 *)(iVar1 + 8));
LAB_0067170d:
            *(undefined4 *)(*(int *)(param_2 + 0x88) + iVar4) = 0xfffffffd;
          }
          iVar3 = iVar3 + 1;
          iVar4 = iVar4 + 0x1c;
        } while (iVar3 < *(int *)(param_2 + 0x80));
      }
      FUN_006712d0(param_1,param_2,8);
    }
    *(uint *)(param_1 + 0x74) = *(uint *)(param_1 + 0x74) | 8;
    FUN_00677ea0(param_1);
  }
  return;
}

