
undefined4 FUN_005ba360(void)

{
  int iVar1;
  int iVar2;
  undefined4 local_4;
  
  if ((DAT_00f13210 == 0) && (DAT_00ef7324 == 0)) {
    return 0;
  }
  DAT_00f13210 = 0;
  if (DAT_00f13248 != 0) {
    if (DAT_00f1324c != 0) {
      FUN_005d2000(DAT_00f13248);
    }
    DAT_00f13248 = 0;
  }
  DAT_00f1324c = 0;
  if ((((((DAT_00f13220 == 0) && (DAT_00f13224 == -1)) && (DAT_00f13225 == -1)) &&
       ((DAT_00f13228 == 1 && (DAT_00f1322c == 1)))) &&
      ((DAT_00f13230 == 1 && ((DAT_00f13234 == 8 && (DAT_00f13238 == 1)))))) &&
     ((DAT_00f1323c == 1 && ((DAT_00f13240 == 1 && (DAT_00f13244 == 8)))))) {
    iVar2 = DAT_00f1321c + ((uint)(DAT_00f13218 == 1) + DAT_00f13214 * 2) * 9;
    if ((&DAT_00f13250)[iVar2] == 0) {
      iVar1 = FUN_005d2970(&DAT_00f13214,&local_4);
      if (iVar1 != 0) {
        FUN_0056bca0(&PTR_PTR_007fd590);
        return 0xffffffff;
      }
      (&DAT_00f13250)[iVar2] = local_4;
    }
    local_4 = (&DAT_00f13250)[iVar2];
  }
  else {
    iVar2 = FUN_005d2970(&DAT_00f13214,&local_4);
    if (iVar2 != 0) {
      FUN_0056bca0(&PTR_PTR_007fd540);
      return 0xffffffff;
    }
    DAT_00f1324c = 1;
  }
  DAT_00f13248 = local_4;
  FUN_005d2d50(local_4,0);
  return 0;
}

