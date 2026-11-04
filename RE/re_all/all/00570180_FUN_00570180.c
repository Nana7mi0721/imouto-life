
undefined4 FUN_00570180(undefined4 *param_1,byte *param_2)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  uint3 *puVar4;
  byte *pbVar5;
  uint uVar6;
  uint3 *puVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint local_c;
  
  bVar1 = *(byte *)(param_1 + 2);
  uVar6 = (uint)bVar1;
  uVar2 = *param_1;
  local_c = 0;
  if (param_2 != (byte *)0x0) {
    iVar3 = param_1[1] + -9;
    puVar4 = (uint3 *)((int)param_1 + 9);
joined_r0x005701b7:
    while (iVar3 != 0) {
      if ((byte)*puVar4 == uVar6) {
        uVar8 = (uint)*(byte *)((int)puVar4 + 1);
        if (uVar8 != uVar6) {
          if (uVar6 < uVar8) {
            uVar8 = uVar8 - 1;
          }
          param_1 = (undefined4 *)(iVar3 + -2);
          puVar7 = (uint3 *)((int)puVar4 + 2);
          uVar9 = uVar8 >> 3;
          if ((uVar8 & 4) != 0) {
            uVar9 = uVar9 | (uint)*(byte *)puVar7 << 5;
            puVar7 = (uint3 *)((int)puVar4 + 3);
            param_1 = (undefined4 *)(iVar3 + -3);
          }
          uVar8 = uVar8 & 3;
          uVar9 = uVar9 + 4;
          if (uVar8 == 0) {
            local_c = (uint)(byte)*puVar7;
            puVar7 = (uint3 *)((int)puVar7 + 1);
            param_1 = (undefined4 *)((int)param_1 + -1);
          }
          else if (uVar8 == 1) {
            local_c = (uint)(ushort)*puVar7;
            puVar7 = (uint3 *)((int)puVar7 + 2);
            param_1 = (undefined4 *)((int)param_1 + -2);
          }
          else if (uVar8 == 2) {
            local_c = (uint)*puVar7;
            puVar7 = (uint3 *)((int)puVar7 + 3);
            param_1 = (undefined4 *)((int)param_1 + -3);
          }
          local_c = local_c + 1;
          uVar8 = local_c;
          iVar3 = (int)param_1;
          puVar4 = puVar7;
          if (local_c < uVar9) goto LAB_00570286;
          pbVar5 = param_2 + -local_c;
          goto LAB_005702b5;
        }
        *param_2 = bVar1;
        param_2 = param_2 + 1;
        iVar3 = iVar3 + -2;
        puVar4 = (uint3 *)((int)puVar4 + 2);
      }
      else {
        *param_2 = (byte)*puVar4;
        param_2 = param_2 + 1;
        iVar3 = iVar3 + -1;
        puVar4 = (uint3 *)((int)puVar4 + 1);
      }
    }
  }
  return uVar2;
LAB_00570286:
  do {
    uVar10 = uVar8;
    FUN_0056d420(param_2,(int)param_2 - uVar10,uVar10);
    param_2 = param_2 + uVar10;
    uVar9 = uVar9 - uVar10;
    uVar8 = uVar10 * 2;
  } while (uVar10 * 2 < uVar9);
  if (uVar9 != 0) {
    pbVar5 = param_2 + uVar10 * -2;
LAB_005702b5:
    FUN_0056d420(param_2,pbVar5,uVar9);
    param_2 = param_2 + uVar9;
  }
  goto joined_r0x005701b7;
}

