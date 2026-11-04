
undefined4
FUN_0065d3a0(int param_1,uint *param_2,ushort *param_3,uint param_4,ushort param_5,
            undefined4 param_6,uint param_7,undefined4 param_8)

{
  uint *puVar1;
  uint uVar2;
  longlong lVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  ushort *puVar9;
  ushort *puVar10;
  ushort *puVar11;
  uint uVar12;
  longlong lVar13;
  
  uVar4 = 0;
  uVar5 = *param_2;
  if (uVar5 != 0) {
    puVar9 = param_3;
    do {
      if ((ushort)param_4 < *puVar9) break;
      uVar4 = uVar4 + 1;
      puVar9 = puVar9 + 0xc;
    } while (uVar4 < uVar5);
  }
  if (uVar4 < uVar5) {
    iVar6 = uVar5 - uVar4;
    puVar9 = param_3 + uVar5 * 0xc;
    do {
      iVar6 = iVar6 + -1;
      puVar10 = puVar9 + -0xc;
      puVar11 = puVar9;
      for (iVar7 = 6; iVar7 != 0; iVar7 = iVar7 + -1) {
        *(undefined4 *)puVar11 = *(undefined4 *)puVar10;
        puVar10 = puVar10 + 2;
        puVar11 = puVar11 + 2;
      }
      puVar9 = puVar9 + -0xc;
    } while (iVar6 != 0);
  }
  param_3 = param_3 + uVar4 * 0xc;
  *param_3 = (ushort)param_4;
  param_3[1] = param_5;
  puVar1 = (uint *)(param_3 + 8);
  *(undefined4 *)(param_3 + 4) = param_6;
  param_3[6] = 0;
  param_3[7] = 0;
  *puVar1 = 0;
  param_3[10] = 0;
  param_3[0xb] = 0;
  uVar5 = *(uint *)(param_1 + 0xc) & 0x80000;
  if (param_7 <= (-(uint)(uVar5 != 0) & 4) + 4) {
    FUN_00650840(puVar1,param_8,param_7);
    *param_2 = *param_2 + 1;
    return 1;
  }
  uVar4 = *(uint *)(param_1 + 0x1d4);
  uVar2 = *(uint *)(param_1 + 0x1d0);
  lVar3 = *(longlong *)(param_1 + 0x1d0);
  uVar12 = param_7 + uVar2;
  uVar8 = uVar4 + CARRY4(param_7,uVar2);
  if (uVar5 == 0) {
    uVar8 = 0;
  }
  if (((uVar8 < uVar4) || ((uVar8 <= uVar4 && (uVar12 < uVar2)))) ||
     ((uVar8 == 0 && (uVar12 < param_7)))) {
    FUN_006512e0(*(undefined4 *)(param_1 + 0x274),"TIFFWriteDirectoryTagData",
                 s_Maximum_TIFF_file_size_exceeded_00a0a69c);
    return 0;
  }
  lVar13 = (**(code **)(param_1 + 0x280))(*(undefined4 *)(param_1 + 0x274),uVar2,uVar4,0);
  if (lVar13 != lVar3) {
    FUN_006512e0(*(undefined4 *)(param_1 + 0x274),"TIFFWriteDirectoryTagData",
                 s_IO_error_writing_tag_data_00a0a758);
    return 0;
  }
  uVar5 = (**(code **)(param_1 + 0x27c))(*(undefined4 *)(param_1 + 0x274),param_8,param_7);
  if (uVar5 != param_7) {
    FUN_006512e0(*(undefined4 *)(param_1 + 0x274),"TIFFWriteDirectoryTagData",
                 s_IO_error_writing_tag_data_00a0a758);
    return 0;
  }
  *(uint *)(param_1 + 0x1d0) = uVar12;
  *(uint *)(param_1 + 0x1d4) = uVar8;
  if ((uVar12 & 1) != 0) {
    *(uint *)(param_1 + 0x1d0) = uVar12 + 1;
    *(uint *)(param_1 + 0x1d4) = uVar8 + (0xfffffffe < uVar12);
  }
  if ((*(uint *)(param_1 + 0xc) & 0x80000) == 0) {
    param_4 = uVar2;
    if ((*(uint *)(param_1 + 0xc) & 0x80) != 0) {
      FUN_0065a600(&param_4);
    }
    FUN_00650840(puVar1,&param_4,4);
    *param_2 = *param_2 + 1;
    return 1;
  }
  *puVar1 = uVar2;
  *(uint *)(param_3 + 10) = uVar4;
  if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
    FUN_0065a620(puVar1);
  }
  *param_2 = *param_2 + 1;
  return 1;
}

