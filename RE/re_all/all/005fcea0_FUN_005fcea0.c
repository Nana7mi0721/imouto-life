
uint FUN_005fcea0(int *param_1,int *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  int unaff_EBX;
  int *piVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  uint uVar10;
  
  if (param_1 == (int *)0x0) {
    return 1;
  }
  puVar5 = (undefined4 *)*param_1;
  piVar9 = param_2;
  uVar4 = (**(code **)(*param_2 + 0x1c))(param_2,*puVar5,puVar5[1],puVar5[2],puVar5[3]);
  if (unaff_EBX != 0) {
    puVar5 = (undefined4 *)*param_1;
    uVar4 = (**(code **)(*param_2 + 0xc))
                      (param_2,*puVar5,puVar5[1],puVar5[2],puVar5[3],param_1[1],param_1[2]);
    if ((-1 < (int)uVar4) && (uVar7 = 0, param_1[3] != 0)) {
      iVar8 = 0;
      while( true ) {
        puVar5 = (undefined4 *)(param_1[4] + iVar8);
        puVar1 = (undefined4 *)puVar5[5];
        puVar2 = (undefined4 *)*param_1;
        uVar4 = (**(code **)(*param_2 + 0x14))
                          (param_2,*puVar2,puVar2[1],puVar2[2],puVar2[3],*puVar5,puVar5[1],puVar5[2]
                           ,puVar5[3],puVar5[4],*puVar1,puVar1[1],puVar1[2],puVar1[3],
                           *(undefined4 *)(param_1[4] + 0x18 + iVar8));
        if ((int)uVar4 < 0) break;
        puVar5 = (undefined4 *)(param_1[4] + iVar8);
        uVar10 = 0;
        piVar6 = param_2;
        if (puVar5[7] != 0) {
          do {
            param_2 = piVar9;
            piVar9 = (int *)(puVar5[8] + uVar10 * 8);
            puVar1 = (undefined4 *)piVar9[1];
            puVar2 = (undefined4 *)*piVar9;
            puVar3 = (undefined4 *)*param_1;
            piVar9 = param_2;
            uVar4 = (**(code **)(*piVar6 + 0x18))
                              (param_2,*puVar3,puVar3[1],puVar3[2],puVar3[3],*puVar5,*puVar2,
                               puVar2[1],puVar2[2],puVar2[3],*puVar1,puVar1[1],puVar1[2],puVar1[3]);
            if ((int)uVar4 < 0) goto LAB_005fd067;
            puVar5 = (undefined4 *)(param_1[4] + iVar8);
            uVar10 = uVar10 + 1;
            piVar6 = param_2;
          } while (uVar10 < (uint)puVar5[7]);
        }
        if ((int)uVar4 < 0) break;
        uVar7 = uVar7 + 1;
        iVar8 = iVar8 + 0x24;
        if ((uint)param_1[3] <= uVar7) break;
      }
    }
  }
LAB_005fd067:
  return -(uint)(uVar4 != 0x80070002) & uVar4;
}

