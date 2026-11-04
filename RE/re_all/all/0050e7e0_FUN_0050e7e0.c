
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_0050e7e0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
            undefined4 *param_5,undefined4 *param_6,undefined4 *param_7,undefined4 *param_8)

{
  undefined4 *puVar1;
  
  if (DAT_00a37ef8 == 0) {
    FUN_00567fe0();
  }
  puVar1 = (undefined4 *)((-(uint)(DAT_00a37eec != 0) & _DAT_00a37ef0) * 0x130 + DAT_00a37ef8);
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = puVar1[4];
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = puVar1[5];
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = puVar1[8];
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = puVar1[9];
  }
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = *puVar1;
  }
  if (param_6 != (undefined4 *)0x0) {
    *param_6 = puVar1[1];
  }
  if (param_7 != (undefined4 *)0x0) {
    *param_7 = puVar1[6];
  }
  if (param_8 != (undefined4 *)0x0) {
    *param_8 = puVar1[7];
  }
  return 0;
}

