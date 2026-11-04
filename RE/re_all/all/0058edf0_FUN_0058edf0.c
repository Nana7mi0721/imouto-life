
undefined4 FUN_0058edf0(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  undefined1 *puVar7;
  int local_10;
  
  if (DAT_00a37dc8 == 1) {
    FUN_005dbab0(param_1);
    return 0;
  }
  iVar2 = FUN_00586970(param_1,1);
  if (iVar2 < 0) {
    return 0xffffffff;
  }
  local_10 = *(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x24);
  iVar2 = *(int *)(param_1 + 0x488);
  pbVar4 = *(byte **)(param_1 + 0x48c);
  iVar5 = *(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x20);
  iVar1 = *(int *)(param_1 + 0xd08);
  puVar7 = *(undefined1 **)(param_1 + 0xd0c);
  do {
    iVar6 = iVar5;
    do {
      if (pbVar4[3] == 0) {
        *puVar7 = 0;
        puVar7[1] = 0;
        puVar7[2] = 0;
      }
      else {
        uVar3 = (uint)((ulonglong)((uint)*pbVar4 * 0xff) / (ulonglong)(longlong)(int)(uint)pbVar4[3]
                      );
        if (0xff < uVar3) {
          uVar3 = 0xff;
        }
        *puVar7 = (char)uVar3;
        uVar3 = (uint)((ulonglong)((uint)pbVar4[1] * 0xff) /
                      (ulonglong)(longlong)(int)(uint)pbVar4[3]);
        if (0xff < uVar3) {
          uVar3 = 0xff;
        }
        puVar7[1] = (char)uVar3;
        uVar3 = (uint)((ulonglong)((uint)pbVar4[2] * 0xff) /
                      (ulonglong)(longlong)(int)(uint)pbVar4[3]);
        if (0xff < uVar3) {
          uVar3 = 0xff;
        }
        puVar7[2] = (char)uVar3;
      }
      puVar7[3] = pbVar4[3];
      pbVar4 = pbVar4 + 4;
      puVar7 = puVar7 + 4;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    pbVar4 = pbVar4 + iVar2 + iVar5 * -4;
    puVar7 = puVar7 + iVar1 + iVar5 * -4;
    local_10 = local_10 + -1;
  } while (local_10 != 0);
  FUN_00586b00();
  return 0;
}

