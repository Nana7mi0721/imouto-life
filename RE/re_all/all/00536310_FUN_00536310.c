
int FUN_00536310(int param_1,uint *param_2,int param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  
  iVar6 = param_3;
  iVar8 = 0;
  if (((*(int *)(param_3 + 0x93628) == 0) || (iVar3 = FUN_00567b30(), iVar3 != 0)) &&
     ((*(int *)(param_3 + 0x38) != 0 || (iVar3 = FUN_00596000(param_3), -1 < iVar3)))) {
    if (0 < param_1) {
      param_3 = param_1;
      do {
        iVar8 = (*(int *)(iVar6 + 0x90d84) + 3) * 0x20 + iVar6;
        if (*(int *)(iVar6 + 0x38) == 0) {
          iVar3 = FUN_005960c0(iVar6,iVar8,*param_2,param_4);
          if (iVar3 < 0) {
            iVar8 = 0;
            goto LAB_00536460;
          }
LAB_00536441:
          *(int *)(iVar6 + 0x90d84) = *(int *)(iVar6 + 0x90d84) + 1;
          if (*(int *)(iVar6 + 0x90d84) == *(int *)(iVar6 + 0x90d88)) {
            *(undefined4 *)(iVar6 + 0x90d84) = 0;
          }
        }
        else {
          uVar1 = *param_2;
          if (uVar1 < 0x10000) {
            iVar3 = *(int *)(*(int *)(iVar6 + 0x54) + uVar1 * 4);
            if (iVar3 != 0) goto LAB_005363d9;
            iVar8 = 0;
          }
          else {
            uVar2 = *(uint *)(*(int *)(iVar6 + 0x44) + 0x14);
            uVar4 = 0;
            if (uVar2 != 0) {
              puVar7 = *(undefined4 **)(iVar6 + 0x58);
              do {
                if (*(uint *)*puVar7 == uVar1) break;
                uVar4 = uVar4 + 1;
                puVar7 = puVar7 + 1;
              } while (uVar4 < *(uint *)(*(int *)(iVar6 + 0x44) + 0x14));
            }
            if (uVar4 != uVar2) {
              iVar3 = *(int *)(*(int *)(iVar6 + 0x58) + uVar4 * 4);
LAB_005363d9:
              if (*(char *)(iVar3 + 4) == '\0') {
                iVar5 = *(int *)(iVar3 + 0x10) + *(int *)(iVar6 + 0x4c);
              }
              else {
                FUN_00570180(*(int *)(iVar3 + 0x10) + *(int *)(iVar6 + 0x4c),
                             *(undefined4 *)(iVar6 + 0x5c));
                iVar5 = *(int *)(iVar6 + 0x5c);
              }
              FUN_00531190(iVar6,iVar8,*param_2,0,*(undefined4 *)(iVar6 + 0x50),iVar5,
                           *(undefined2 *)(iVar3 + 0xc),*(undefined2 *)(iVar3 + 0xe),
                           *(undefined4 *)(iVar3 + 0x14),(int)*(short *)(iVar3 + 6),
                           (int)*(short *)(iVar3 + 8),(int)*(short *)(iVar3 + 10),param_4);
              goto LAB_00536441;
            }
            iVar8 = 0;
          }
        }
LAB_00536460:
        param_2 = param_2 + 1;
        param_3 = param_3 + -1;
      } while (param_3 != 0);
    }
    FUN_0052f110(iVar6);
    if ((*(int *)(iVar6 + 0x38) != 0) || (iVar6 = FUN_00596590(iVar6), -1 < iVar6)) {
      return iVar8;
    }
  }
  return 0;
}

