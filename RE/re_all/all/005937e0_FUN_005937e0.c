
undefined4
FUN_005937e0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  undefined1 uVar6;
  int iVar7;
  undefined1 *puVar8;
  int local_c;
  
  if (DAT_00a37dc8 == 1) {
    FUN_005dbc20(param_1,param_2,param_3,param_4,param_5,param_6);
    return 0;
  }
  iVar1 = FUN_00586970(param_1,1);
  if (iVar1 < 0) {
    return 0xffffffff;
  }
  iVar4 = *(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x20);
  puVar3 = *(undefined1 **)(param_1 + 0x48c);
  puVar2 = *(undefined1 **)(param_1 + 0xd0c);
  local_c = *(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x24);
  iVar1 = *(int *)(param_1 + 0xd08);
  iVar7 = *(int *)(param_1 + 0x488) + iVar4 * -4;
  puVar8 = *(undefined1 **)(param_1 + 0x8cc);
  do {
    iVar5 = iVar4;
    do {
      switch(param_4) {
      case 0:
        uVar6 = puVar3[2];
        break;
      case 1:
        uVar6 = puVar3[1];
        break;
      case 2:
        uVar6 = *puVar3;
        break;
      case 3:
        uVar6 = puVar3[3];
        break;
      case 4:
        uVar6 = puVar8[2];
        break;
      case 5:
        uVar6 = puVar8[1];
        break;
      case 6:
        uVar6 = *puVar8;
        break;
      case 7:
        uVar6 = puVar8[3];
        break;
      default:
        goto switchD_0059388d_default;
      }
      *puVar2 = uVar6;
switchD_0059388d_default:
      switch(param_3) {
      case 0:
        uVar6 = puVar3[2];
        break;
      case 1:
        uVar6 = puVar3[1];
        break;
      case 2:
        uVar6 = *puVar3;
        break;
      case 3:
        uVar6 = puVar3[3];
        break;
      case 4:
        uVar6 = puVar8[2];
        break;
      case 5:
        uVar6 = puVar8[1];
        break;
      case 6:
        uVar6 = *puVar8;
        break;
      case 7:
        uVar6 = puVar8[3];
        break;
      default:
        goto switchD_005938c3_default;
      }
      puVar2[1] = uVar6;
switchD_005938c3_default:
      switch(param_2) {
      case 0:
        uVar6 = puVar3[2];
        break;
      case 1:
        uVar6 = puVar3[1];
        break;
      case 2:
        uVar6 = *puVar3;
        break;
      case 3:
        uVar6 = puVar3[3];
        break;
      case 4:
        uVar6 = puVar8[2];
        break;
      case 5:
        uVar6 = puVar8[1];
        break;
      case 6:
        uVar6 = *puVar8;
        break;
      case 7:
        uVar6 = puVar8[3];
        break;
      default:
        goto switchD_005938fa_default;
      }
      puVar2[2] = uVar6;
switchD_005938fa_default:
      switch(param_5) {
      case 0:
        uVar6 = puVar3[2];
        break;
      case 1:
        uVar6 = puVar3[1];
        break;
      case 2:
        uVar6 = *puVar3;
        break;
      case 3:
        uVar6 = puVar3[3];
        break;
      case 4:
        uVar6 = puVar8[2];
        break;
      case 5:
        uVar6 = puVar8[1];
        break;
      case 6:
        uVar6 = *puVar8;
        break;
      case 7:
        uVar6 = puVar8[3];
        break;
      default:
        goto switchD_00593931_default;
      }
      puVar2[3] = uVar6;
switchD_00593931_default:
      puVar3 = puVar3 + 4;
      puVar8 = puVar8 + 4;
      puVar2 = puVar2 + 4;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    puVar2 = puVar2 + iVar1 + iVar4 * -4;
    puVar3 = puVar3 + iVar7;
    puVar8 = puVar8 + iVar7;
    local_c = local_c + -1;
    if (local_c == 0) {
      FUN_00586b00();
      return 0;
    }
  } while( true );
}

