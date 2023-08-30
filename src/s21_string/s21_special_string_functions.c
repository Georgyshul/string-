#include "../s21_string.h"

void *s21_to_upper(const char *str) {
  char *upper_str = NULL;

  if (str) {
    int length = s21_strlen(str);
    upper_str = (char *)calloc(length + 1, sizeof(char));

    if (upper_str) {
      for (int i = 0; i < length; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
          upper_str[i] = str[i] + ('A' - 'a');
        } else {
          upper_str[i] = str[i];
        }
      }
      upper_str[length] = '\0';
    }
  }

  return (void *)upper_str;
}

void *s21_to_lower(const char *str) {
  char *lower_str = NULL;

  if (str) {
    int length = s21_strlen(str);
    lower_str = (char *)calloc(length + 1, sizeof(char));

    if (lower_str) {
      for (int i = 0; i < length; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
          lower_str[i] = str[i] + ('a' - 'A');
        } else {
          lower_str[i] = str[i];
        }
      }
      lower_str[length] = '\0';
    }
  }

  return (void *)lower_str;
}

void *s21_insert(const char *src, const char *str, size_t start_index) {
  char *inserted_str = NULL;

  if (src && str) {
    size_t length_src = s21_strlen(src);
    size_t length_str = s21_strlen(str);

    if (start_index <= length_src) {
      inserted_str = (char *)calloc(length_src + length_str + 1, sizeof(char));

      if (inserted_str) {
        size_t idx = 0;

        for (; idx < start_index; idx++) {
          inserted_str[idx] = src[idx];
        }

        for (size_t i = 0; i < length_str; i++) {
          inserted_str[idx + i] = str[i];
        }

        for (; idx < length_src; idx++) {
          inserted_str[idx + length_str] = src[idx];
        }
        inserted_str[length_src + length_str] = '\0';
      }
    }
  }
  return (void *)inserted_str;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *trimmed_str = NULL;

  if (src && trim_chars) {
    int length = s21_strlen(src);

    int left_idx = 0;
    int right_idx = length - 1;

    while (left_idx < length && s21_strchr(trim_chars, src[left_idx])) {
      left_idx++;
    }

    while (right_idx >= left_idx && s21_strchr(trim_chars, src[right_idx])) {
      right_idx--;
    }

    trimmed_str = (char *)calloc(right_idx - left_idx + 2, sizeof(char));

    if (trimmed_str) {
      for (int i = 0; i < right_idx - left_idx + 1; i++) {
        trimmed_str[i] = src[i + left_idx];
      }
      trimmed_str[right_idx - left_idx + 1] = '\0';
    }
  }
  return (void *)trimmed_str;
}