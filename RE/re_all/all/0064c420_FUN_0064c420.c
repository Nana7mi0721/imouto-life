
undefined4 FUN_0064c420(int *param_1)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  byte bVar5;
  int iVar6;
  undefined4 uVar7;
  uint *puVar8;
  uint *puVar9;
  uint uVar10;
  byte bVar12;
  byte bVar11;
  uint uVar13;
  uint local_c;
  
  iVar2 = param_1[0xb];
  iVar3 = param_1[9];
  uVar1 = *(ushort *)(param_1 + 6);
  iVar4 = param_1[10];
  iVar6 = FUN_006507d0(((int)(8 / (ulonglong)(longlong)(int)(uint)uVar1) + 1) * 0x400);
  param_1[0x10] = iVar6;
  if (iVar6 == 0) {
    uVar7 = FUN_006507b0(*param_1,s_No_space_for_Palette_mapping_tab_00a06688);
    FUN_006512e0(*(undefined4 *)(*param_1 + 0x274),uVar7);
    return 0;
  }
  puVar8 = (uint *)(iVar6 + 0x400);
  uVar10 = 0;
  do {
    *(uint **)(param_1[0x10] + uVar10 * 4) = puVar8;
    bVar11 = (byte)((int)uVar10 >> 4);
    bVar12 = (byte)((int)uVar10 >> 2);
    bVar5 = (byte)uVar10;
    switch((uint)uVar1) {
    case 1:
      local_c = (uint)(bVar5 >> 7);
      iVar6 = local_c * 2;
      *puVar8 = ((*(ushort *)(iVar6 + iVar2) | 0xffffff00) << 8 | (uint)*(byte *)(iVar4 + iVar6)) <<
                8 | (uint)*(byte *)(iVar6 + iVar3);
      local_c = (uint)((byte)((int)uVar10 >> 6) & 1);
      iVar6 = local_c * 2;
      puVar8[1] = ((*(ushort *)(iVar6 + iVar2) | 0xffffff00) << 8 | (uint)*(byte *)(iVar4 + iVar6))
                  << 8 | (uint)*(byte *)(iVar6 + iVar3);
      local_c = (uint)((byte)((int)uVar10 >> 5) & 1);
      iVar6 = local_c * 2;
      puVar8[2] = ((*(ushort *)(iVar6 + iVar2) | 0xffffff00) << 8 | (uint)*(byte *)(iVar4 + iVar6))
                  << 8 | (uint)*(byte *)(iVar6 + iVar3);
      local_c = (uint)(bVar11 & 1);
      iVar6 = local_c * 2;
      puVar9 = puVar8 + 7;
      puVar8[3] = ((*(ushort *)(iVar6 + iVar2) | 0xffffff00) << 8 | (uint)*(byte *)(iVar4 + iVar6))
                  << 8 | (uint)*(byte *)(iVar6 + iVar3);
      local_c = (uint)((byte)((int)uVar10 >> 3) & 1);
      iVar6 = local_c * 2;
      puVar8[4] = ((*(ushort *)(iVar6 + iVar2) | 0xffffff00) << 8 | (uint)*(byte *)(iVar4 + iVar6))
                  << 8 | (uint)*(byte *)(iVar6 + iVar3);
      local_c = (uint)(bVar12 & 1);
      iVar6 = local_c * 2;
      puVar8[5] = ((*(ushort *)(iVar6 + iVar2) | 0xffffff00) << 8 | (uint)*(byte *)(iVar4 + iVar6))
                  << 8 | (uint)*(byte *)(iVar6 + iVar3);
      local_c = (uint)((byte)((int)uVar10 >> 1) & 1);
      iVar6 = local_c * 2;
      puVar8[6] = ((*(ushort *)(iVar6 + iVar2) | 0xffffff00) << 8 | (uint)*(byte *)(iVar4 + iVar6))
                  << 8 | (uint)*(byte *)(iVar6 + iVar3);
      local_c = (uint)(bVar5 & 1);
      iVar6 = local_c * 2;
      uVar13 = ((*(ushort *)(iVar6 + iVar2) | 0xffffff00) << 8 | (uint)*(byte *)(iVar4 + iVar6)) <<
               8;
      break;
    case 2:
      local_c = (uint)(bVar5 >> 6);
      puVar9 = puVar8 + 3;
      iVar6 = local_c * 2;
      *puVar8 = ((*(ushort *)(iVar6 + iVar2) | 0xffffff00) << 8 | (uint)*(byte *)(iVar4 + iVar6)) <<
                8 | (uint)*(byte *)(iVar6 + iVar3);
      local_c = (uint)(bVar11 & 3);
      iVar6 = local_c * 2;
      puVar8[1] = ((*(ushort *)(iVar6 + iVar2) | 0xffffff00) << 8 | (uint)*(byte *)(iVar4 + iVar6))
                  << 8 | (uint)*(byte *)(iVar6 + iVar3);
      local_c = (uint)(bVar12 & 3);
      iVar6 = local_c * 2;
      puVar8[2] = ((*(ushort *)(iVar6 + iVar2) | 0xffffff00) << 8 | (uint)*(byte *)(iVar4 + iVar6))
                  << 8 | (uint)*(byte *)(iVar6 + iVar3);
      local_c = (uint)(bVar5 & 3);
      iVar6 = local_c * 2;
      uVar13 = ((*(ushort *)(iVar6 + iVar2) | 0xffffff00) << 8 | (uint)*(byte *)(iVar4 + iVar6)) <<
               8;
      break;
    default:
      goto switchD_0064c4af_caseD_3;
    case 4:
      local_c = (uint)(bVar5 >> 4);
      puVar9 = puVar8 + 1;
      iVar6 = local_c * 2;
      *puVar8 = ((*(ushort *)(iVar6 + iVar2) | 0xffffff00) << 8 | (uint)*(byte *)(iVar4 + iVar6)) <<
                8 | (uint)*(byte *)(iVar6 + iVar3);
      local_c = (uint)(bVar5 & 0xf);
      iVar6 = local_c * 2;
      uVar13 = ((*(ushort *)(iVar6 + iVar2) | 0xffffff00) << 8 | (uint)*(byte *)(iVar4 + iVar6)) <<
               8;
      break;
    case 8:
      iVar6 = (uVar10 & 0xff) * 2;
      uVar13 = ((*(ushort *)(iVar6 + iVar2) | 0xffffff00) << 8 | (uint)*(byte *)(iVar6 + iVar4)) <<
               8;
      puVar9 = puVar8;
    }
    *puVar9 = uVar13 | *(byte *)(iVar6 + iVar3);
    puVar8 = puVar9 + 1;
switchD_0064c4af_caseD_3:
    uVar10 = uVar10 + 1;
    if (0xff < (int)uVar10) {
      return 1;
    }
  } while( true );
}

