
undefined4 FUN_0065e450(int param_1,int param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  uint *puVar7;
  undefined4 *puVar8;
  uint uVar9;
  uint uVar10;
  undefined8 uVar11;
  int local_10;
  int local_c;
  
  local_10 = -1;
  local_c = -1;
  param_2 = param_2 * 8;
  piVar5 = (int *)(param_2 + *(int *)(param_1 + 0xac));
  iVar1 = *piVar5;
  iVar2 = piVar5[1];
  uVar6 = (int)param_4 >> 0x1f;
  if ((iVar1 != 0 || iVar2 != 0) &&
     (*(int *)(param_1 + 0x1c8) != 0 || *(int *)(param_1 + 0x1cc) != 0)) goto LAB_0065e588;
  puVar7 = (uint *)(param_2 + *(int *)(param_1 + 0xb0));
  uVar4 = *puVar7;
  uVar3 = puVar7[1];
  if ((uVar4 == 0 && uVar3 == 0) || (iVar1 == 0 && iVar2 == 0)) {
LAB_0065e519:
    uVar11 = (**(code **)(param_1 + 0x280))(*(undefined4 *)(param_1 + 0x274),0,0,2);
    *(undefined8 *)(param_2 + *(int *)(param_1 + 0xac)) = uVar11;
    *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 0x200000;
  }
  else {
    if ((uVar3 < uVar6) || ((uVar3 <= uVar6 && (uVar4 < param_4)))) goto LAB_0065e519;
    uVar11 = (**(code **)(param_1 + 0x280))(*(undefined4 *)(param_1 + 0x274),iVar1,iVar2,0);
    piVar5 = (int *)(param_2 + *(int *)(param_1 + 0xac));
    if (((int)uVar11 != *piVar5) || ((int)((ulonglong)uVar11 >> 0x20) != piVar5[1])) {
      FUN_006512e0(*(undefined4 *)(param_1 + 0x274),"TIFFAppendToStrip",
                   s_Seek_error_at_scanline__lu_00a0a8dc,*(undefined4 *)(param_1 + 0x1bc));
      return 0;
    }
  }
  puVar8 = (undefined4 *)(param_2 + *(int *)(param_1 + 0xac));
  *(undefined4 *)(param_1 + 0x1c8) = *puVar8;
  *(undefined4 *)(param_1 + 0x1cc) = puVar8[1];
  local_10 = *(int *)(param_2 + *(int *)(param_1 + 0xb0));
  puVar8 = (undefined4 *)(param_2 + *(int *)(param_1 + 0xb0));
  local_c = puVar8[1];
  *puVar8 = 0;
  puVar8[1] = 0;
LAB_0065e588:
  uVar4 = *(uint *)(param_1 + 0x1cc);
  uVar3 = *(uint *)(param_1 + 0x1c8);
  uVar9 = param_4 + uVar3;
  uVar10 = uVar6 + uVar4 + (uint)CARRY4(param_4,uVar3);
  if ((*(byte *)(param_1 + 0xe) & 8) == 0) {
    uVar10 = 0;
  }
  if ((uVar10 < uVar4) ||
     ((((uVar10 <= uVar4 && (uVar9 < uVar3)) || (uVar10 < uVar6)) ||
      ((uVar10 <= uVar6 && (uVar9 < param_4)))))) {
    FUN_006512e0(*(undefined4 *)(param_1 + 0x274),"TIFFAppendToStrip",
                 s_Maximum_TIFF_file_size_exceeded_00a0a69c);
    return 0;
  }
  uVar4 = (**(code **)(param_1 + 0x27c))(*(undefined4 *)(param_1 + 0x274),param_3,param_4);
  if (uVar4 != param_4) {
    FUN_006512e0(*(undefined4 *)(param_1 + 0x274),"TIFFAppendToStrip",
                 s_Write_error_at_scanline__lu_00a0a8c0,*(undefined4 *)(param_1 + 0x1bc));
    return 0;
  }
  *(uint *)(param_1 + 0x1c8) = uVar9;
  *(uint *)(param_1 + 0x1cc) = uVar10;
  uVar4 = *(uint *)(param_2 + *(int *)(param_1 + 0xb0));
  piVar5 = (int *)(param_2 + *(int *)(param_1 + 0xb0));
  *piVar5 = uVar4 + param_4;
  piVar5[1] = piVar5[1] + uVar6 + (uint)CARRY4(uVar4,param_4);
  piVar5 = (int *)(param_2 + *(int *)(param_1 + 0xb0));
  if ((*piVar5 != local_10) || (piVar5[1] != local_c)) {
    *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 0x200000;
  }
  return 1;
}

