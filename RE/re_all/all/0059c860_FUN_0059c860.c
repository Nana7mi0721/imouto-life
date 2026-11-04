
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

undefined4 __fastcall
FUN_0059c860(int param_1,undefined4 *param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 local_1000 [1023];
  undefined4 uStack_4;
  
  uStack_4 = 0x59c86a;
  if (DAT_00f3a04c == 0) {
    return 0xffffffff;
  }
  if (param_2 == (undefined4 *)0x0) {
    iVar3 = param_4 * 0x100 + 0x2717c + param_3;
    iVar2 = param_4 * 0x5030 + 0x14 + param_3;
    iVar1 = param_5 + param_1;
    switch(param_4) {
    case 0:
    case 3:
      FUN_0056d380(local_1000,0,0x1000);
      if (param_5 < iVar1) {
        iVar6 = param_5 << 4;
        iVar5 = param_5;
        do {
          if (*(byte *)(iVar5 + iVar3) != 0xff) {
            puVar4 = (undefined4 *)((uint)*(byte *)(iVar5 + iVar3) * 0x140c + iVar6 + 0x40c + iVar2)
            ;
            *(undefined4 *)((int)local_1000 + iVar6) = *puVar4;
            *(undefined4 *)((int)local_1000 + iVar6 + 4) = puVar4[1];
            *(undefined4 *)((int)local_1000 + iVar6 + 8) = puVar4[2];
            *(undefined4 *)((int)local_1000 + iVar6 + 0xc) = puVar4[3];
          }
          iVar5 = iVar5 + 1;
          iVar6 = iVar6 + 0x10;
        } while (iVar5 < iVar1);
      }
      param_2 = local_1000 + param_5 * 4;
      break;
    case 1:
    case 4:
      FUN_0056d380(local_1000,0,0x100);
      if (param_5 < iVar1) {
        iVar6 = param_5 << 4;
        iVar5 = param_5;
        do {
          if (*(byte *)(iVar5 + iVar3) != 0xff) {
            puVar4 = (undefined4 *)((uint)*(byte *)(iVar5 + iVar3) * 0x140c + iVar6 + 0x40c + iVar2)
            ;
            *(undefined4 *)((int)local_1000 + iVar6) = *puVar4;
            *(undefined4 *)((int)local_1000 + iVar6 + 4) = puVar4[1];
            *(undefined4 *)((int)local_1000 + iVar6 + 8) = puVar4[2];
            *(undefined4 *)((int)local_1000 + iVar6 + 0xc) = puVar4[3];
          }
          iVar5 = iVar5 + 1;
          iVar6 = iVar6 + 0x10;
        } while (iVar5 < iVar1);
      }
      param_2 = local_1000 + param_5 * 4;
      break;
    case 2:
    case 5:
      FUN_0056d380(local_1000,0,0x40);
      for (iVar5 = param_5; iVar5 < iVar1; iVar5 = iVar5 + 1) {
        if (*(byte *)(iVar5 + iVar3) != 0xff) {
          local_1000[iVar5] =
               *(undefined4 *)(iVar2 + 0x40c + ((uint)*(byte *)(iVar5 + iVar3) * 0x503 + iVar5) * 4)
          ;
        }
      }
      param_2 = local_1000 + param_5;
      break;
    default:
      goto switchD_0059c8d1_default;
    }
  }
  switch(param_4) {
  case 0:
    if (DAT_00a37dc8 == 1) {
      FUN_005d3c50(param_5,param_2,param_1);
    }
    param_1 = param_1 << 4;
    param_3 = (param_5 + 0x1fd4) * 0x10 + param_3;
    break;
  case 1:
    if (DAT_00a37dc8 == 1) {
      FUN_005d3c70(param_5,param_2,param_1);
    }
    param_1 = param_1 << 4;
    param_3 = param_5 * 0x10 + 0x2114c + param_3;
    break;
  case 2:
    if (DAT_00a37dc8 == 1) {
      FUN_005d3c90(param_5,param_2,param_1);
    }
    param_1 = param_1 * 4;
    param_3 = param_3 + 0x22558 + param_5 * 4;
    break;
  case 3:
    if (DAT_00a37dc8 == 1) {
      FUN_005d3d40(param_5,param_2,param_1);
    }
    param_1 = param_1 << 4;
    param_3 = param_5 * 0x10 + 0x23964 + param_3;
    break;
  case 4:
    if (DAT_00a37dc8 == 1) {
      FUN_005d3d60(param_5,param_2,param_1);
    }
    param_1 = param_1 << 4;
    param_3 = (param_5 + 0x24d7) * 0x10 + param_3;
    break;
  case 5:
    if (DAT_00a37dc8 == 1) {
      FUN_005d3d80(param_5,param_2,param_1);
    }
    param_1 = param_1 * 4;
    param_3 = param_3 + 0x2617c + param_5 * 4;
    break;
  default:
    goto switchD_0059c8d1_default;
  }
  FUN_0056d420(param_3,param_2,param_1);
switchD_0059c8d1_default:
  return 0;
}

