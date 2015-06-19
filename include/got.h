#ifndef GOT_H_
# define GOT_H_

typedef struct s_quote {
  char *author;
  char *quote;
}t_quote;

# define GOT_QUOTES_SIZE 15

t_quote got_quotes[] = {
  {"Ygritte", "You know nothing, Jon Snow."},
  {"Jaime Lannister", "Give my regards to the Night’s Watch. I’m sure it will be thrilling. And if it’s not, it’s only for life."},
  {"Eddard ‘Ned’ Stark", "War was easier than daughters."},
  {"Daenerys Targaryen", "I am a Khaleesi of the Dothraki. I am the wife of the great Kahl and I carry his son inside me. The next time you raise a hand to me will be the last time you have hands."},
  {"Tyrion Lannister", "A Lannister always pays his debts."},
  {"Eddard ‘Ned’ Stark", "The man who passes the sentence should swing the sword."},
  {"Tonny Stark", "I'm a Stark!"},
  {"Cersei Lannister", "When you play the game of thrones, you win or you die."},
  {"Tyrion Lannister", "I will hurt you for this. A day will come when you think you are safe and happy, and your joy will turn to ashes in your mouth. And you will know the debt is paid."},
  {"Daenerys Targaryen", "A dragon is not a slave."},
  {"Tyrion Lannister", "And now I’ve struck a king. Did my hand fall from my wrist?"},
  {"Catelyn Stark", "Wise men do not make demands of kings."},
  {"Margaery Tyrell", "I want to be THE queen."},
  {"Cersei Lannister", "If you ever call me sister again I’ll have you strangled in your sleep."},
  {"Tywin Lannister", "Any man who must say, I am the king, is no true king."}
};

int get_random(int, int);

#endif /* !GOT_H_ */
