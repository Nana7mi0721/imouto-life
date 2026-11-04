
undefined4 FUN_0064c050(int *param_1)

{
  ushort uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  uint *puVar6;
  uint *puVar7;
  uint uVar8;
  byte bVar9;
  uint uVar10;
  
  piVar3 = param_1;
  uVar1 = *(ushort *)(param_1 + 6);
  iVar2 = param_1[0xe];
  iVar4 = (int)(8 / (ulonglong)(longlong)(int)(uint)uVar1);
  if (iVar4 == 0) {
    iVar4 = 1;
  }
  iVar4 = FUN_006507d0((iVar4 + 1) * 0x400);
  param_1[0xf] = iVar4;
  if (iVar4 == 0) {
    uVar5 = FUN_006507b0(*param_1,s_No_space_for_B_W_mapping_table_00a06668);
    FUN_006512e0(*(undefined4 *)(*param_1 + 0x274),uVar5);
    return 0;
  }
  puVar6 = (uint *)(iVar4 + 0x400);
  uVar8 = 0;
  do {
    *(uint **)(piVar3[0xf] + uVar8 * 4) = puVar6;
    if (uVar1 - 1 < 0x10) {
      uVar10 = (int)uVar8 >> 4;
      switch(uVar1) {
      case 1:
        param_1 = (int *)(uint)*(byte *)(((int)uVar8 >> 7) + iVar2);
        *puVar6 = (((uint)param_1 | 0xffffff00) << 8 | (uint)param_1) << 8 | (uint)param_1;
        param_1 = (int *)(uint)*(byte *)(((int)uVar8 >> 6 & 1U) + iVar2);
        puVar6[1] = (((uint)param_1 | 0xffffff00) << 8 | (uint)param_1) << 8 | (uint)param_1;
        param_1 = (int *)(uint)*(byte *)(((int)uVar8 >> 5 & 1U) + iVar2);
        puVar6[2] = (((uint)param_1 | 0xffffff00) << 8 | (uint)param_1) << 8 | (uint)param_1;
        param_1 = (int *)(uint)*(byte *)((uVar10 & 1) + iVar2);
        puVar6[3] = (((uint)param_1 | 0xffffff00) << 8 | (uint)param_1) << 8 | (uint)param_1;
        param_1 = (int *)(uint)*(byte *)(((int)uVar8 >> 3 & 1U) + iVar2);
        puVar6[4] = (((uint)param_1 | 0xffffff00) << 8 | (uint)param_1) << 8 | (uint)param_1;
        param_1 = (int *)(uint)*(byte *)(((int)uVar8 >> 2 & 1U) + iVar2);
        puVar7 = puVar6 + 7;
        puVar6[5] = (((uint)param_1 | 0xffffff00) << 8 | (uint)param_1) << 8 | (uint)param_1;
        param_1 = (int *)(uint)*(byte *)(((int)uVar8 >> 1 & 1U) + iVar2);
        puVar6[6] = (((uint)param_1 | 0xffffff00) << 8 | (uint)param_1) << 8 | (uint)param_1;
        bVar9 = *(byte *)((uVar8 & 1) + iVar2);
        break;
      case 2:
        puVar7 = puVar6 + 3;
        param_1 = (int *)(uint)*(byte *)(((int)uVar8 >> 6) + iVar2);
        *puVar6 = (((uint)param_1 | 0xffffff00) << 8 | (uint)param_1) << 8 | (uint)param_1;
        param_1 = (int *)(uint)*(byte *)((uVar10 & 3) + iVar2);
        puVar6[1] = (((uint)param_1 | 0xffffff00) << 8 | (uint)param_1) << 8 | (uint)param_1;
        param_1 = (int *)(uint)*(byte *)(((int)uVar8 >> 2 & 3U) + iVar2);
        puVar6[2] = (((uint)param_1 | 0xffffff00) << 8 | (uint)param_1) << 8 | (uint)param_1;
        bVar9 = *(byte *)((uVar8 & 3) + iVar2);
        break;
      default:
        goto switchD_0064c0cf_caseD_3;
      case 4:
        puVar7 = puVar6 + 1;
        param_1 = (int *)(uint)*(byte *)(uVar10 + iVar2);
        *puVar6 = (((uint)param_1 | 0xffffff00) << 8 | (uint)param_1) << 8 | (uint)param_1;
        bVar9 = *(byte *)((uVar8 & 0xf) + iVar2);
        break;
      case 8:
      case 0x10:
        bVar9 = *(byte *)(uVar8 + iVar2);
        puVar7 = puVar6;
      }
      param_1 = (int *)(uint)bVar9;
      *puVar7 = (((uint)param_1 | 0xffffff00) << 8 | (uint)param_1) << 8 | (uint)param_1;
      puVar6 = puVar7 + 1;
    }
switchD_0064c0cf_caseD_3:
    uVar8 = uVar8 + 1;
    if (0xff < (int)uVar8) {
      return 1;
    }
  } while( true );
}

