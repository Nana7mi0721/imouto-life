
undefined1 * __thiscall FUN_00474f60(undefined1 *param_1,undefined1 *param_2)

{
  uint local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  *param_1 = *param_2;
  for (local_8 = 0; local_8 < 0xa00; local_8 = local_8 + 1) {
    param_1[local_8 + 1] = param_2[local_8 + 1];
  }
  for (local_c = 0; local_c < 0xa00; local_c = local_c + 1) {
    param_1[local_c + 0xa01] = param_2[local_c + 0xa01];
  }
  param_1[0x1401] = param_2[0x1401];
  *(undefined4 *)(param_1 + 0x1404) = *(undefined4 *)(param_2 + 0x1404);
  *(undefined4 *)(param_1 + 0x1408) = *(undefined4 *)(param_2 + 0x1408);
  *(undefined4 *)(param_1 + 0x140c) = *(undefined4 *)(param_2 + 0x140c);
  *(undefined4 *)(param_1 + 0x1410) = *(undefined4 *)(param_2 + 0x1410);
  *(undefined4 *)(param_1 + 0x1414) = *(undefined4 *)(param_2 + 0x1414);
  *(undefined4 *)(param_1 + 0x1418) = *(undefined4 *)(param_2 + 0x1418);
  *(undefined4 *)(param_1 + 0x141c) = *(undefined4 *)(param_2 + 0x141c);
  for (local_10 = 0; local_10 < 5; local_10 = local_10 + 1) {
    *(undefined4 *)(param_1 + local_10 * 4 + 0x1420) =
         *(undefined4 *)(param_2 + local_10 * 4 + 0x1420);
  }
  for (local_14 = 0; local_14 < 5; local_14 = local_14 + 1) {
    *(undefined4 *)(param_1 + local_14 * 4 + 0x1434) =
         *(undefined4 *)(param_2 + local_14 * 4 + 0x1434);
  }
  *(undefined4 *)(param_1 + 0x1448) = *(undefined4 *)(param_2 + 0x1448);
  *(undefined4 *)(param_1 + 0x144c) = *(undefined4 *)(param_2 + 0x144c);
  FUN_004cb840(param_2 + 0x1450);
  FUN_004cb840(param_2 + 0x146c);
  FUN_004cb840(param_2 + 0x1488);
  *(undefined4 *)(param_1 + 0x14a4) = *(undefined4 *)(param_2 + 0x14a4);
  for (local_18 = 0; local_18 < 10; local_18 = local_18 + 1) {
    *(undefined4 *)(param_1 + local_18 * 4 + 0x14a8) =
         *(undefined4 *)(param_2 + local_18 * 4 + 0x14a8);
  }
  FUN_004cb840(param_2 + 0x14d0);
  *(undefined4 *)(param_1 + 0x14ec) = *(undefined4 *)(param_2 + 0x14ec);
  *(undefined4 *)(param_1 + 0x14f0) = *(undefined4 *)(param_2 + 0x14f0);
  *(undefined4 *)(param_1 + 0x14f4) = *(undefined4 *)(param_2 + 0x14f4);
  *(undefined4 *)(param_1 + 0x14f8) = *(undefined4 *)(param_2 + 0x14f8);
  *(undefined4 *)(param_1 + 0x14fc) = *(undefined4 *)(param_2 + 0x14fc);
  FUN_004753d0(param_2 + 0x1500);
  *(undefined4 *)(param_1 + 0x1504) = *(undefined4 *)(param_2 + 0x1504);
  for (local_1c = 0; local_1c < 0x200; local_1c = local_1c + 1) {
    param_1[local_1c + 0x1508] = param_2[local_1c + 0x1508];
  }
  *(undefined4 *)(param_1 + 0x1708) = *(undefined4 *)(param_2 + 0x1708);
  *(undefined4 *)(param_1 + 0x170c) = *(undefined4 *)(param_2 + 0x170c);
  *(undefined4 *)(param_1 + 0x1710) = *(undefined4 *)(param_2 + 0x1710);
  *(undefined4 *)(param_1 + 0x1714) = *(undefined4 *)(param_2 + 0x1714);
  *(undefined4 *)(param_1 + 0x1718) = *(undefined4 *)(param_2 + 0x1718);
  *(undefined4 *)(param_1 + 0x171c) = *(undefined4 *)(param_2 + 0x171c);
  *(undefined4 *)(param_1 + 0x1720) = *(undefined4 *)(param_2 + 0x1720);
  FUN_004cb840(param_2 + 0x1724);
  FUN_004cb840(param_2 + 0x1740);
  FUN_004cb840(param_2 + 0x175c);
  FUN_004cb840(param_2 + 0x1778);
  *(undefined4 *)(param_1 + 0x1794) = *(undefined4 *)(param_2 + 0x1794);
  *(undefined4 *)(param_1 + 0x1798) = *(undefined4 *)(param_2 + 0x1798);
  *(undefined4 *)(param_1 + 0x179c) = *(undefined4 *)(param_2 + 0x179c);
  *(undefined4 *)(param_1 + 0x17a0) = *(undefined4 *)(param_2 + 0x17a0);
  *(undefined4 *)(param_1 + 0x17a4) = *(undefined4 *)(param_2 + 0x17a4);
  *(undefined4 *)(param_1 + 0x17a8) = *(undefined4 *)(param_2 + 0x17a8);
  return param_1;
}

