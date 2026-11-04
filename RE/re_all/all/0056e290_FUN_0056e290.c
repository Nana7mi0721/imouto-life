
undefined4 FUN_0056e290(int param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  ushort uVar4;
  int unaff_EBX;
  int iVar5;
  int local_8;
  int local_4;
  
  iVar1 = param_2;
  param_2._0_2_ = 0;
  iVar5 = 0;
  iVar2 = FUN_00572fc0();
  do {
    if (((iVar2 == 0) || (iVar2 == 0x5c)) || (iVar2 == 0x2f)) {
      if (param_3 != (int *)0x0) {
        *param_3 = iVar5;
      }
      iVar2 = ((int)(iVar5 + 4 + (iVar5 + 4 >> 0x1f & 3U)) >> 2) * 4;
      FUN_0056d380(iVar5 + iVar1,0,iVar2 - iVar5);
      *(short *)(iVar1 + 0x400) = (short)param_2;
      *(short *)(iVar1 + 0x402) = (short)((int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2);
      return 0;
    }
    if (iVar2 - 0x61U < 0x1a) {
      pbVar3 = (byte *)(iVar5 + iVar1);
      thunk_FUN_00573310(iVar2 + -0x20,*(undefined4 *)(param_1 + 0x38),pbVar3,0x400 - iVar5);
      if (local_8 == 1) {
        uVar4 = (ushort)*pbVar3;
      }
      else if (local_8 == 2) {
        uVar4 = (ushort)*(byte *)(iVar5 + 1 + iVar1) + (ushort)*pbVar3;
      }
      else {
        if (local_8 != 4) {
          iVar2 = 0;
          if (0 < local_8) {
            do {
              param_2._0_2_ = (short)param_2 + (ushort)pbVar3[iVar2];
              iVar2 = iVar2 + 1;
            } while (iVar2 < local_8);
          }
          goto LAB_0056e40f;
        }
        uVar4 = (ushort)*(byte *)(iVar5 + 3 + iVar1) + (ushort)*(byte *)(iVar5 + 2 + iVar1) +
                (ushort)*(byte *)(iVar5 + 1 + iVar1) + (ushort)*pbVar3;
      }
LAB_0056e40a:
      param_2._0_2_ = (short)param_2 + uVar4;
    }
    else {
      if (local_8 == 1) {
        *(undefined1 *)(iVar5 + iVar1) = *(undefined1 *)(iVar5 + unaff_EBX);
        uVar4 = (ushort)*(byte *)(iVar5 + unaff_EBX);
        goto LAB_0056e40a;
      }
      if (local_8 == 2) {
        *(undefined2 *)(iVar5 + iVar1) = *(undefined2 *)(iVar5 + unaff_EBX);
        param_2._0_2_ =
             (short)param_2 +
             (ushort)*(byte *)(iVar5 + 1 + unaff_EBX) + (ushort)*(byte *)(iVar5 + unaff_EBX);
      }
      else {
        if (local_8 == 4) {
          *(undefined4 *)(iVar5 + iVar1) = *(undefined4 *)(iVar5 + unaff_EBX);
          uVar4 = (ushort)*(byte *)(iVar5 + 3 + unaff_EBX) +
                  (ushort)*(byte *)(iVar5 + 2 + unaff_EBX) +
                  (ushort)*(byte *)(iVar5 + 1 + unaff_EBX) + (ushort)*(byte *)(iVar5 + unaff_EBX);
          goto LAB_0056e40a;
        }
        if (0 < local_8) {
          pbVar3 = (byte *)(iVar5 + unaff_EBX);
          local_4 = local_8;
          do {
            pbVar3[iVar1 - unaff_EBX] = *pbVar3;
            param_2._0_2_ = (short)param_2 + (ushort)*pbVar3;
            pbVar3 = pbVar3 + 1;
            local_4 = local_4 + -1;
          } while (local_4 != 0);
          local_4 = 0;
        }
      }
    }
LAB_0056e40f:
    iVar5 = iVar5 + local_8;
    iVar2 = FUN_00572fc0(iVar5 + unaff_EBX,*(undefined4 *)(param_1 + 0x38),&local_8);
  } while( true );
}

